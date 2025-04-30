#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Base class representing a generic customer
class Customer {
private:
  int id;                           // Customer ID
  std::string firstName, lastName;  // Customer's first and last name
  std::vector<std::string> history; // Vector for recording transaction history

public:
  // Constructor
  Customer(int customerId, std::string fName, std::string lName)
      : id(customerId), firstName(fName), lastName(lName) {}

  // Get customer ID
  int getID() const { return id; }

  // Get full customer name
  std::string getName() const { return firstName + " " + lastName; }

  // Getter for history
  const std::vector<std::string> &getHistory() const {
    return history; // Return the history list
  }

  // Add transaction to customer history
  void addTransaction(const std::string &transaction) {
    history.push_back(transaction);
    // std::cout << transaction << std::endl;
  }

  // Display customer transaction history
  void displayHistory() const {
    std::cout << "History for " << getName() << ":\n";
    if (history.empty()) {
      std::cout << "No history for " << getName() << std::endl;
    } else {
      for (const std::string &record : history) {
        std::cout << record << std::endl;
      }
    }
  }

  // Check if Customer Has Borrowed a Movie
  bool hasBorrowed(const std::string &movieTitle) const {
    return std::any_of(history.begin(), history.end(),
                       [&movieTitle](const std::string &record) {
                         return record == "Borrowed " + movieTitle;
                       });
  }
};

#endif
