#ifndef CUSTOMERDB_H
#define CUSTOMERDB_H

#include "customer.h"
#include "hashTable.h"

// Manages a collection of customers
class CustomerDB {
private:
  HashTable<int, Customer *> customers; // Hash table for storing customers

public:
  // Destructor to free allocated memory for customers
  ~CustomerDB();

  // Adds a new customer to the database
  void addCustomer(Customer *c);

  // Retrieves a customer by ID
  Customer *getCustomer(int id) const;
};

#endif
