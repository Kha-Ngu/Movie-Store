#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

// Base class representing a generic movie
class Movie {
protected:
  int stock;            // Number of copies available
  std::string director; // Director of the movie
  std::string title;    // Title of the movie
  int year;             // Release year of the movie

public:
  // Constructor: Initializes a movie with stock, director, title, and year
  Movie(int stock, const std::string &director, const std::string &title,
        int year)
      : stock(stock), director(director), title(title), year(year) {}

  // Virtual destructor to allow proper cleanup in derived classes
  virtual ~Movie() = default;

  // Getter for stock quantity
  int getStock() const { return stock; }

  // Getter for movie director
  std::string getDirector() const { return director; }

  // Getter for movie title
  std::string getTitle() const { return title; }

  // Getter for release year
  int getYear() const { return year; }

  // Decreases stock when a movie is borrowed (if stock is available)
  void borrowMovie() {
    if (stock > 0) {
      stock--;
    }
  }

  // Increases stock when a movie is returned
  void returnMovie() { stock++; }

  // Pure virtual function: Returns a unique key for identifying the movie
  virtual std::string getKey() const = 0;

  // Pure virtual function: Returns the type of movie (e.g., Comedy, Drama,
  // Classic)
  virtual std::string getType() const = 0;

  // Checks if a given key matches the movie's key
  bool matchesKey(const std::string &key) const {
    return getKey() ==
           key; // getKey() should return the correct key for each movie type
  }

  // Virtual function to display movie details (can be overridden by subclasses)
  virtual void display() const {
    std::cout << getType() << ", " << stock << ", " << director << ", " << title
              << ", " << year << std::endl;
  }

  // Pure virtual function: Returns formatted movie information
  virtual std::string getMovieInfo() const = 0;
};

#endif
