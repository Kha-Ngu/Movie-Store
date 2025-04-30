#include "customerDb.h"
#include <iostream>

// Destructor: Frees allocated memory for customers
CustomerDB::~CustomerDB() {
  std::vector<Customer *> customersList;
  customers.getAllValues(customersList); // Retrieve all stored customers

  for (Customer *customer : customersList) {
    delete customer; // Free allocated memory
  }
}

// Adds a new customer to the database
void CustomerDB::addCustomer(Customer *c) {
  customers.insert(c->getID(), c); // Ensure customers are stored correctly
}

// Retrieves a customer by ID
Customer *CustomerDB::getCustomer(int id) const {
  Customer *customer = nullptr;
  if (customers.find(id, customer)) {
    return customer;
  }
  std::cerr << "Invalid customer ID " << id << "\n";
  return nullptr;
}
