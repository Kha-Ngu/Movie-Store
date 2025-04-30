#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "command.h"
#include "commandFactory.h"

// Represents an inventory command to display available movies
class InventoryCommand : public Command {
public:
  // Constructor
  InventoryCommand();

  // Executes the command to display movie inventory
  void execute(MovieStore &store, CustomerDB &customers) override;

  // Destructor (default)
  ~InventoryCommand() override {}
};

#endif
