#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <iostream>
#include <map>

// Forward declaration of Command class
class Command;

class CommandFactory {
public:
  // Creates a command based on the provided type
  virtual Command *createCommand(std::istream &input) const = 0;

  // Factory method to create a command dynamically
  static Command *create(char type, std::istream &input);

  // Registers a command type in the factory
  static void registerType(char type, CommandFactory *factory);

private:
  // Returns the registry containing command types
  static std::map<char, CommandFactory *> &getRegistry();
};

#endif
