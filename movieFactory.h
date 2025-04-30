#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <iostream>
#include <map>

class Movie; // Forward Declaration

class MovieFactory {
public:
  // Pure virtual function to create a movie, to be implemented by derived
  // factories
  virtual Movie *createMovie(std::istream &input) const = 0;

  // Creates a movie object based on the provided type and input stream
  static Movie *create(char type, std::istream &input);

protected:
  // Registers a movie type with its corresponding factory
  static void registerType(char type, MovieFactory *factory);

private:
  // Retrieves the registry of movie types mapped to their respective factories
  static std::map<char, MovieFactory *> &getRegistry();
};

#endif
