#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "command.h"
#include "commandFactory.h"
#include <string>

class BorrowCommand : public Command {
private:
  int customerID;       // ID of the customer borrowing the movie
  std::string movieKey; // Unique key identifying the movie

public:
  // Constructor to initialize BorrowCommand with a customer ID and movie key
  BorrowCommand(int id, std::string key);

  // Executes the borrow command by checking inventory and updating history
  void execute(MovieStore &store, CustomerDB &customers) override;

  // Destructor (default)
  ~BorrowCommand() override {}
};

#endif
