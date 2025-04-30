#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>

template <typename K, typename V> class HashTable {
private:
  static const int TABLE_SIZE = 101; // Prime number for better distribution
  std::vector<std::list<std::pair<K, V>>> table;

  int hashFunction(const K &key) const {
    std::hash<K> hasher;
    return hasher(key) % TABLE_SIZE;
  }

public:
  HashTable() : table(TABLE_SIZE) {}

  // Insert key-value pair
  void insert(const K &key, V value) {
    int index = hashFunction(key);
    for (auto &pair : table[index]) {
      if (pair.first == key) {
        pair.second = value; // Update value if key exists
        return;
      }
    }
    table[index].emplace_back(key, value);
  }

  // Find a value by key
  bool find(const K &key, V &value) const {
    int index = hashFunction(key);
    for (const auto &pair : table[index]) {
      if (pair.first == key) {
        value = pair.second;
        return true;
      }
    }
    return false;
  }

  // Remove a key-value pair
  bool remove(const K &key) {
    int index = hashFunction(key);
    auto &chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
      if (it->first == key) {
        chain.erase(it);
        return true;
      }
    }
    return false;
  }

  // Display all stored items (for debugging)
  void display() const {
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
      if (!table[i].empty()) {
        std::cout << "Bucket " << i << ": ";
        for (const auto &pair : table[i]) {
          std::cout << "[" << pair.first << "] ";
        }
        std::cout << std::endl;
      }
    }
  }

  // Collect all values from the hash table into a vector
  void getAllValues(std::vector<V> &values) const {
    for (const auto &bucket : table) {
      for (const auto &pair : bucket) {
        values.push_back(pair.second);
      }
    }
  }

  // Collect all unique keys from the hash table
  void getAllKeys(std::vector<K> &keys) const {
    for (const auto &bucket : table) {
      for (const auto &pair : bucket) {
        keys.push_back(pair.first);
      }
    }
  }
};

#endif
