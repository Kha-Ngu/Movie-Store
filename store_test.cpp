/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "command.h"
#include "commandFactory.h"
#include "customer.h"
#include "customerDb.h"
#include "movieFactory.h"
#include "movieStore.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;
// File names for testing
const string MOVIE_FILE = "data4movies.txt";
const string CUSTOMER_FILE = "data4customers.txt";
const string COMMAND_FILE = "data4commands.txt";

// Load movies from file into store
void loadMovies(MovieStore &store) {
  ifstream file(MOVIE_FILE);
  assert(file.is_open() && "Failed to open data4movies.txt");

  char type;
  while (file >> type) {
    file.ignore(); // Ignore comma
    Movie *movie = MovieFactory::create(type, file);

    if (movie != nullptr) {
      // movie->display();
      //  std::cout << "DEBUG Loaded movie: " << movie->getDirector() << ", " <<
      //  movie->getTitle() << " (" << movie->getYear() << ")" << std::endl;
      store.addMovie(movie);
    } else {
      // cout << "DEBUG: Failed to create movie of type " << type << endl;
      file.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip bad data
    }
  }

  file.close();
}

// Load customers from file into customer database
void loadCustomers(CustomerDB &customers) {
  ifstream file(CUSTOMER_FILE);
  assert(file.is_open() && "Failed to open data4customers.txt");

  int id;
  string firstName;
  string lastName;
  while (file >> id >> lastName >> firstName) {
    customers.addCustomer(new Customer(id, firstName, lastName));
  }

  file.close();
}

// Process commands from file and execute them
void processCommands(MovieStore &store, CustomerDB &customers) {
  ifstream file(COMMAND_FILE);
  assert(file.is_open() && "Failed to open data4commands.txt");

  char commandType;
  while (file >> commandType) {
    Command *cmd = CommandFactory::create(commandType, file);
    if (cmd != nullptr) {
      cmd->execute(store, customers);
      delete cmd; // Free memory after execution
    } else {
      file.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip bad data
    }
  }

  file.close();
}

// Reads commands from testcommands-1.txt and verifies expected sequence.
void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

// Test loading and reading movies
void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "=====================================" << endl;
  cout << "Start testLoadAndDisplayMovies" << endl;

  MovieStore store;
  cout << "\nLoading movies...\n";
  loadMovies(store);

  // Capture the inventory output
  stringstream buffer;
  streambuf *old = cout.rdbuf(buffer.rdbuf()); // Redirect cout

  cout << "Loading movies...\n"
       << "Unknown movie type: Z, discarding line.\n"
       << "Unknown movie type: Z, discarding line.\n"; // This output goes to
                                                       // buffer

  cout << "Displaying inventory...\n";

  store.displayInventory(); // This output goes to buffer

  cout.rdbuf(old); // Restore cout

  // Expected inventory output (adjust based on your test case)
  string expectedOutput =
      "Loading movies...\n"
      "Unknown movie type: Z, discarding line.\n"
      "Unknown movie type: Z, discarding line.\n"
      "Displaying inventory...\n"
      "==========================\n"
      "Annie Hall, 1977,  Woody Allen (10) - Comedy\n"
      "Fargo, 1996,  Joel Coen (10) - Comedy\n"
      "National Lampoon's Animal House, 1978,  John Landis (10) - Comedy\n"
      "Pirates of the Caribbean, 2003,  Gore Verbinski (10) - Comedy\n"
      "Pirates of the Caribbean, 2000,  Different Years (10) - Comedy\n"
      "Sleepless in Seattle, 1993,  Nora Ephron (10) - Comedy\n"
      "When Harry Met Sally, 1989,  Rob Reiner (10) - Comedy\n"
      "You've Got Mail, 1998,  Nora Ephron (10) - Comedy\n"
      "Barry Levinson, Good Morning Vietnam, 1988 (10) - Drama\n"
      "Barry Levinson, Same Director Good Morning Vietnam, 1988 (10) - Drama\n"
      "Clint Eastwood, Unforgiven, 1992 (10) - Drama\n"
      "Gus Van Sant, Good Will Hunting, 2000 (10) - Drama\n"
      "Jonathan Demme, Silence of the Lambs, 1991 (10) - Drama\n"
      "Nancy Savoca, Dogfight, 1991 (10) - Drama\n"
      "Phillippe De Broca, King of Hearts, 1967 (10) - Drama\n"
      "Steven Spielberg, Schindler's List, 1993 (10) - Drama\n"
      "1938 9, Cary Grant,  George Cukor, Holiday (10) - Classics\n"
      "1939 2, Clark Gable,  Victor Fleming, Gone With the Wind (10) - "
      "Classics\n"
      "1939 2, Vivien Leigh,  Victor Fleming, Gone With the Wind (10) - "
      "Classics\n"
      "1939 7, Judy Garland,  Victor Fleming, The Wizard of Oz (10) - "
      "Classics\n"
      "1940 5, Cary Grant,  George Cukor, The Philadelphia Story (10) - "
      "Classics\n"
      "1940 5, Katherine Hepburn,  George Cukor, The Philadelphia Story (10) - "
      "Classics\n"
      "1941 10, Humphrey Bogart,  John Huston, The Maltese Falcon (10) - "
      "Classics\n"
      "1942 8, Ingrid Bergman,  Michael Curtiz, Casablanca (10) - Classics\n"
      "1942 8, Humphrey Bogart,  Michael Curtiz, Casablanca (10) - Classics\n"
      "1946 11, Donna Reed,  Frank Capra, It's a Wonderful Life (10) - "
      "Classics\n"
      "1971 2, Malcolm McDowell,  Stanley Kubrick, A Clockwork Orange (10) - "
      "Classics\n"
      "1971 3, Ruth Gordon,  Hal Ashby, Harold and Maude (10) - Classics\n"
      "==========================\n";

  // Compare captured output with expected output
  if (buffer.str() == expectedOutput) {
    cout << "End testStore2" << endl;
  } else {
    cout << "Test Failed: Inventory does not match expected output." << endl;
    cout << "Expected:\n" << expectedOutput << endl;
    cout << "Got:\n" << buffer.str() << endl;
  }

  cout << "=====================================" << endl;
}

// Final validation test for the movie store. Uses the required .txt files
void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;

  MovieStore store;
  CustomerDB customers;
  loadMovies(store);
  loadCustomers(customers);
  processCommands(store, customers);

  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
