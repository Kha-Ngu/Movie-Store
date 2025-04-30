#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "command.h"
#include "commandFactory.h"

// Represents a command to display a customer's transaction history
class HistoryCommand : public Command {
private:
  int customerID; // ID of the customer whose history is being retrieved

public:
  // Constructor: Initializes the command with a customer ID
  explicit HistoryCommand(int id);

  // Executes the command to display the customer's transaction history
  void execute(MovieStore &store, CustomerDB &customers) override;

  // Destructor (default)
  ~HistoryCommand() override {}
};

#endif
