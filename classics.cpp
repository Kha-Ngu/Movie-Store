#include "classics.h"
#include <iostream>

// Displays movie details for Classics
void Classics::display() const {
  std::cout << year << " " << month << ", " << actor << ", " << director << ", "
            << title << " (" << stock << ") - Classics\n";
}

// Returns formatted movie info for transaction history
std::string Classics::getMovieInfo() const {
  return std::to_string(year) + " " + std::to_string(month) + ", " + actor +
         ", " + director + ", " + title + " (" + std::to_string(stock) +
         ") - Classics";
}

// Generates a unique key for this movie type
std::string Classics::getKey() const {
  return std::to_string(month) + " " + std::to_string(year) + " " + actor;
}

// Returns the movie type identifier ('C' for Classics)
std::string Classics::getType() const { return "C"; }

// Returns the actor of the movie
std::string Classics::getActor() const { return actor; }

// Returns the month of release
int Classics::getMonth() const { return month; }

class ClassicsFactory : public MovieFactory {
public:
  // Registers this factory with the MovieFactory registry
  ClassicsFactory() { registerType('C', this); }
  // Creates a Classics movie object from input stream
  Movie *createMovie(std::istream &input) const {
    int stock;
    int month;
    int year;
    std::string director;
    std::string title;
    std::string firstName;
    std::string lastName;
    std::string actor;

    input >> stock;                     // Read stock count
    input.ignore();                     // Ignore comma
    std::getline(input, director, ','); // Read director
    input.ignore();                     // Ignore comma
    std::getline(input, title, ',');    // Read title
    input.ignore();                     // Ignore comma
    input >> firstName >> lastName >> month >>
        year; // Read actor name, month, and year

    actor = firstName + " " +
            lastName; // Combine first and last name for full actor name
    return new Classics(stock, director, title, actor, month, year);
  }
};

// Ensure the factory registers
static ClassicsFactory registerClassics;
