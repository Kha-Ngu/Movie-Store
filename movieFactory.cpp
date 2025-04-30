#include "movieFactory.h"
#include "limits"
#include "movie.h"
#include <iostream>
#include <map>

// Static registry for movie creation
std::map<char, MovieFactory *> &MovieFactory::getRegistry() {
  static std::map<char, MovieFactory *> registry;
  return registry;
}

// Register a movie type
void MovieFactory::registerType(char type, MovieFactory *factory) {
  getRegistry()[type] = factory;
}

// Create a movie object based on type
Movie *MovieFactory::create(char type, std::istream &input) {
  auto it = getRegistry().find(type);
  if (it == getRegistry().end()) {
    std::cerr << "Unknown movie type: " << type << ", discarding line.\n";
    input.ignore(std::numeric_limits<std::streamsize>::max(),
                 '\n'); // Skip bad data
    return nullptr;
  }
  return it->second->createMovie(input);
}
