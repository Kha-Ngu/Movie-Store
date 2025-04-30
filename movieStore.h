#ifndef MOVIESTORE_H
#define MOVIESTORE_H

#include "movie.h"
#include <unordered_map>
using namespace std;

// Manages the inventory of movies in the store
class MovieStore {
private:
  unordered_map<std::string, Movie *>
      inventory; // Stores movies with their unique keys
  unordered_map<std::string, int>
      originalStock; // Tracks the original stock for each movie

public:
  // Destructor: Frees dynamically allocated movies
  ~MovieStore();

  // Adds a movie to the inventory
  void addMovie(Movie *movie);

  // Retrieves the current inventory of movies
  unordered_map<std::string, Movie *> getInventory() const { return inventory; }

  // Finds a movie in the inventory by its key
  Movie *findMovie(const std::string &key);

  // Displays all movies in the inventory in a formatted output
  void displayInventory() const;

  // Retrieves the original stock count for a given movie
  int getOriginalStock(const std::string &movieKey) const;
};

#endif
