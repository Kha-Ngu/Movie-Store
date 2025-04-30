#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include "movieFactory.h"
#include <string>

using namespace std;

// Represents a Drama movie, derived from the Movie class
class Drama : public Movie {
public:
  // Constructor to initialize a Drama movie object
  Drama(int stock, const std::string &director, const std::string &title,
        int year);

  // Displays the movie details in a formatted manner
  void display() const override;

  // Returns formatted movie details for transaction history
  string getMovieInfo() const override;

  // Generates a unique key for this movie type
  std::string getKey() const override;

  // Returns the movie type identifier ('D' for Drama)
  std::string getType() const override;

private:
  // Utility function to trim leading and trailing spaces
  static std::string trim(const std::string &str);
};

#endif
