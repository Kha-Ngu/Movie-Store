#include "commandFactory.h"
#include <map>

// Registry for command creation
std::map<char, CommandFactory *> &CommandFactory::getRegistry() {
  static std::map<char, CommandFactory *> registry;
  return registry;
}

// Register a command type
void CommandFactory::registerType(char type, CommandFactory *factory) {
  getRegistry()[type] = factory;
}

// Create a command object based on type
Command *CommandFactory::create(char type, std::istream &input) {
  auto it = getRegistry().find(type);
  if (it != getRegistry().end()) {
    return it->second->createCommand(input);
  }
  std::cerr << "Invalid command type: " << type << ", discarding line.\n";
  return nullptr;
}
