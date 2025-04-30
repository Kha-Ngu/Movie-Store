#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include "movieFactory.h"
#include <string>

// Represents a Comedy movie type
class Comedy : public Movie {
public:
  // Constructor to initialize a Comedy movie with stock, director, title, and
  // year
  Comedy(int stock, const std::string &director, const std::string &title,
         int year)
      : Movie(stock, director, title, year) {}

  // Displays movie details for Comedy
  void display() const override;

  // Returns formatted movie info for transaction history
  std::string getMovieInfo() const override;

  // Generates a unique key for this movie type
  std::string getKey() const override;

  // Returns the movie type identifier ('F' for Comedy)
  std::string getType() const override;
};

#endif
