#ifndef COMMAND_H
#define COMMAND_H

class MovieStore; // Forward Declaration for MovieStore
class CustomerDB; // Forward Declaration for CustomerDB

// Abstract base class for all commands
class Command {
public:
  // Executes the command on the given MovieStore and CustomerDB
  virtual void execute(MovieStore &store, CustomerDB &customers) = 0;

  // Virtual destructor to ensure proper cleanup in derived classes
  virtual ~Command() {} // Ensure vtable is created
};

#endif
