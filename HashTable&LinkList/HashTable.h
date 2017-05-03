#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "LinkedList.h"

class HashTable {
 public:
  HashTable ();
  HashTable (int c);
  HashTable (const HashTable& ht);
  ~HashTable() = default;
  HashTable& operator=(const HashTable& ht);

  bool add(const Val& v);
  bool remove(const Val& v);
  bool search(const Val& v);

  int size() const;
  int capacity() const;
  std::vector<Val> keys() const;
  float loadFactor() const;

  HashTable setunion(const HashTable& ht) const;

  static std::uint32_t hash(const Val& key);
  std::size_t compress(std::uint32_t hash) const;

  constexpr static int defaultCapacity {101};

  void printTable(const std::string& label) const;

 private:
  // Add your member variables and any private member functions here
  std::unique_ptr<LinkedList[]> arr {std::make_unique<LinkedList[]>(defaultCapacity)};
  std::size_t arrSize{defaultCapacity};
  std::uint32_t numOfItem{0};
  std::uint32_t numOfUsedKey{0};
  void deep_copy(const HashTable& ht);
  bool prime(uint32_t v) const;
};

#endif
