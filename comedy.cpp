#include "comedy.h"
#include <iostream>

// Displays movie details for Comedy
void Comedy::display() const {
  std::cout << title << ", " << year << ", " << director << " (" << stock
            << ") - Comedy\n";
}

// Returns formatted movie info for transaction history
std::string Comedy::getMovieInfo() const {
  return title + ", " + std::to_string(year) + ", " + director + " (" +
         std::to_string(stock) + ") - Comedy";
}

// Generates a unique key for this movie type
std::string Comedy::getKey() const {
  return title + ", " + std::to_string(year);
}

// Returns the movie type identifier ('F' for Comedy)
std::string Comedy::getType() const { return "F"; }

// Factory class for creating Comedy movies
class ComedyFactory : public MovieFactory {
public:
  // Registers this factory with the MovieFactory registry
  ComedyFactory() { registerType('F', this); }

  // Creates a Comedy movie object from input stream
  Movie *createMovie(std::istream &input) const override {
    int stock;
    int year;
    std::string director;
    std::string title;

    input >> stock;                     // Read stock count
    input.ignore();                     // Ignore comma
    std::getline(input, director, ','); // Read director
    input.ignore();                     // Ignore comma
    std::getline(input, title, ',');    // Read title
    input >> year;                      // Read release year

    return new Comedy(stock, director, title, year);
  }
};

// Ensure the factory registers itself with the MovieFactory registry
static ComedyFactory registerComedy;
