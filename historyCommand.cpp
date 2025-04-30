#include "historyCommand.h"
#include "customer.h"
#include "customerDb.h"
#include <iostream>

// Constructor to initialize a HistoryCommand with a customer ID
HistoryCommand::HistoryCommand(int id) : customerID(id) {}

// Executes the history retrieval command for a given customer
void HistoryCommand::execute(MovieStore &store, CustomerDB &customers) {
  (void)store; // Suppress unused parameter warning
  Customer *customer = customers.getCustomer(customerID);
  if (customer == nullptr) {
    std::cerr << "Invalid customer ID " << customerID << "\n";
    return;
  }
  std::cout << "==========================\n";
  customer->displayHistory();
  std::cout << "==========================\n";
}

// Factory for registering the HistoryCommand type
class HistoryCommandFactory : public CommandFactory {
public:
  // Registers 'H' as the command type for history retrieval
  HistoryCommandFactory() { registerType('H', this); }

  // Creates a HistoryCommand object from input stream
  Command *createCommand(std::istream &input) const override {
    int customerID;
    input >> customerID;
    return new HistoryCommand(customerID);
  }
};

// Ensure a single instance of HistoryCommandFactory is registered
static HistoryCommandFactory registerHistory;
