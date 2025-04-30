#include "inventoryCommand.h"
#include "movieStore.h"
#include <iostream>

// Constructor for InventoryCommand
InventoryCommand::InventoryCommand() {}

// Executes the inventory command to display available movies
void InventoryCommand::execute(MovieStore &store, CustomerDB &customers) {
  (void)customers; // Suppress unused parameter warning
  std::cout << "==========================\nDisplaying Inventory...\n";
  store.displayInventory();
}

// Factory class to create InventoryCommand instances
class InventoryCommandFactory : public CommandFactory {
public:
  // Registers InventoryCommand ('I') in the command factory
  InventoryCommandFactory() { registerType('I', this); }

  // Creates an InventoryCommand instance from input stream
  Command *createCommand(std::istream &input) const override {
    (void)input; // Suppress unused parameter warning
    return new InventoryCommand();
  }
};

// Register InventoryCommand factory to enable self-registration
static InventoryCommandFactory registerInventory;
