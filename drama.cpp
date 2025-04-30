#include "drama.h"
#include <iostream>

// Constructor to initialize a Drama movie object
Drama::Drama(int stock, const std::string &director, const std::string &title,
             int year)
    : Movie(stock, director, title, year) {}

// Displays the movie details in a formatted manner
void Drama::display() const {
  std::cout << trim(director) << ", " << trim(title) << ", " << year << " ("
            << stock << ") - Drama\n";
}

// Returns formatted movie details for transaction history
string Drama::getMovieInfo() const {
  return trim(director) + ", " + trim(title) + ", " + std::to_string(year) +
         " (" + std::to_string(stock) + ") - Drama";
}

// Generates a unique key for this movie type
std::string Drama::getKey() const {
  return trim(director) + ", " + trim(title) + ",";
}

// Returns the movie type identifier ('D' for Drama)
std::string Drama::getType() const { return "D"; }

// Utility function to trim leading and trailing spaces
std::string Drama::trim(const std::string &str) {
  const auto first = str.find_first_not_of(" \t");
  if (first == std::string::npos) {
    return ""; // No non-space characters
  }
  const auto last = str.find_last_not_of(" \t");
  return str.substr(first, last - first + 1);
}

// Factory class for creating Drama movies
class DramaFactory : public MovieFactory {
public:
  // Registers this factory with the MovieFactory registry
  DramaFactory() { registerType('D', this); }

  // Creates a Drama movie object from input stream
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
    input.ignore();                     // Ignore comma
    input >> year;                      // Read release year

    return new Drama(stock, director, title, year);
  }
};

// Ensure the factory registers itself with the MovieFactory registry
static DramaFactory registerDrama;