#include "movieStore.h"
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

// Destructor: Free dynamically allocated movies
MovieStore::~MovieStore() {
  for (auto &pair : inventory) {
    delete pair.second; // Delete the movie pointer
  }
}

// Add a movie to inventory
void MovieStore::addMovie(Movie *movie) {
  if (movie == nullptr) {
    return;
  }
  inventory[movie->getKey()] = movie;
  // Store original stock count the first time the movie is added
  if (originalStock.find(movie->getKey()) == originalStock.end()) {
    originalStock[movie->getKey()] = movie->getStock();
  }
}

int MovieStore::getOriginalStock(const std::string &movieKey) const {
  auto it = originalStock.find(movieKey);
  if (it != originalStock.end()) {
    return it->second; // Return stored original stock
  }
  return -1; // Return -1 if movie is not found
}

// Find a movie in the inventory
Movie *MovieStore::findMovie(const std::string &key) {
  auto it = inventory.find(key); // Use unordered_map's find method
  if (it != inventory.end()) {
    // std::cout << "DEBUG FINDMOVIE: KEY " << it->second->getKey() << endl;
    // std::cout << "DEBUG FINDMOVIE: MOVIE ";
    return it->second; // Return the movie pointer
  }
  // Movie not found, print error message using validateMovieExistence
  std::cerr << "Invalid Movie: Movie not found in inventory " << key << "\n";
  return nullptr; // Return nullptr if movie not found
}

// Display inventory sorted dynamically by genre in reverse alphabetical order
void MovieStore::displayInventory() const {
  // Step 1: Retrieve all movies from personal HashTable
  std::vector<Movie *> allMovies;
  for (const auto &pair : inventory) {
    allMovies.push_back(pair.second); // Add each movie to the vector
  }

  // Step 2: Categorize movies dynamically by type in a new HashTable
  std::unordered_map<std::string, std::vector<Movie *>> categorizedMovies;
  for (Movie *movie : allMovies) {
    categorizedMovies[movie->getType()].push_back(movie);
  }

  // Step 3: Extract categories from HashTable & sort them in reverse order
  std::vector<std::string> categories;
  for (const auto &category : categorizedMovies) {
    categories.push_back(category.first); // Get all category keys (movie types)
  }
  std::sort(categories.rbegin(), categories.rend());

  std::cout << "==========================\n";

  // Step 4: Sort movies within each category and display them
  for (const std::string &category : categories) {
    std::vector<Movie *> movies = categorizedMovies[category];

    std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {
      if (a->getType() ==
          "C") { // Classics sorted by year (ascending), then actor
        return a->getYear() < b->getYear() ||
               (a->getYear() == b->getYear() && a->getTitle() < b->getTitle());
      }
      if (a->getType() == "D") { // Dramas sorted by director, then title
        return a->getDirector() < b->getDirector() ||
               (a->getDirector() == b->getDirector() &&
                a->getTitle() < b->getTitle());
      } // Comedies & other types sorted by title
      return a->getTitle() < b->getTitle();
    });

    // Step 5: Print movies in sorted order
    for (Movie *movie : movies) {
      movie->display();
    }
  }
  std::cout << "==========================\n";
}