#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"
#include "movieFactory.h"
#include <string>

// Represents a Classics movie type
class Classics : public Movie {
public:
  // Constructor to initialize a Classics movie with stock, director, title,
  // actor, month, and year
  Classics(int stock, const std::string &director, const std::string &title,
           const std::string &actor, int month, int year)
      : Movie(stock, director, title, year), actor(actor), month(month) {}

  // Displays movie details for Classics
  void display() const override;

  // Returns formatted movie info for transaction history
  std::string getMovieInfo() const override;

  // Generates a unique key for this movie type
  std::string getKey() const override;

  // Returns the movie type identifier ('C' for Classics)
  std::string getType() const override;

  // Returns the actor of the movie
  std::string getActor() const;

  // Returns the month of release
  int getMonth() const;

private:
  std::string actor; // Lead actor for Classics movie
  int month;         // Month of release
};

#endif
