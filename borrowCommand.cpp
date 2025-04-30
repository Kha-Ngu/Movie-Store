#include "borrowCommand.h"
#include "customer.h"
#include "customerDb.h"
#include "movie.h"
#include "movieStore.h"
#include "sstream"
#include <iostream>

// Constructor: Initializes BorrowCommand with customer ID and movie key
BorrowCommand::BorrowCommand(int id, std::string key)
    : customerID(id), movieKey(key) {}

// Executes the borrow command, checking stock and updating transaction history
void BorrowCommand::execute(MovieStore &store, CustomerDB &customers) {

  Customer *customer = customers.getCustomer(customerID);
  if (customer == nullptr) {
    std::cerr << "Invalid customer ID " << customerID << "\n";
    return;
  }

  Movie *movie = nullptr;
  for (const auto &pair : store.getInventory()) {
    if (pair.second->getKey() == movieKey) {
      // std::cout << "DEBUG BC: Key " << pair.second->getKey() << "MOVIE KEY "
      // << movieKey << endl;
      movie = store.findMovie(movieKey);
    }
  }

  if (movie == nullptr) {
    std::cerr << "Movie not found: " << movieKey << "\n";
    return;
  }

  // Check if the movie is available for borrowing
  if (movie->getStock() > 0) {
    movie->borrowMovie();
    customer->addTransaction("Borrowed " + movie->getMovieInfo());
    // std::cout << "DEBUG TRANSACTION: " << customer->getName() << " borrowed "
    // << movie->getTitle() << "\n";
  } else {
    std::cerr << "ERROR: " << customer->getName() << " could NOT borrow "
              << movie->getTitle() << ", out of stock.\n";
  }
}

class BorrowCommandFactory : public CommandFactory {
public:
  // Registers BorrowCommand ('B') in the command factory
  BorrowCommandFactory() { registerType('B', this); }
  // Creates a BorrowCommand instance from input stream
  Command *createCommand(std::istream &input) const override {
    int customerID;
    char mediaType;
    char movieType;
    std::string movieKey;

    input >> customerID >> mediaType >>
        movieType; // Read customer ID, media type (ignored), and movie type

    if (mediaType !=
        'D') { // If media type is something other than 'D', discard line
      std::cerr << "Invalid media type: " << mediaType
                << ", discarding line.\n";
      return nullptr;
    }

    std::getline(input, movieKey);
    movieKey.erase(0, movieKey.find_first_not_of(" ")); // Remove leading spaces

    return new BorrowCommand(customerID, movieKey);
  }
};

static BorrowCommandFactory registerBorrow;
