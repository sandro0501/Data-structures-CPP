
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  unsigned long operator()(const Data&) const noexcept;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data> {
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
  using DictionaryContainer<Data>::size;

  unsigned long table_size = 16;
  unsigned long a;
  unsigned long b;             
  const unsigned long prime = 1610612741;

  // ...
  Hashable<Data> hash_function;

public:

  // Destructor
  // ~HashTable() specifiers
  ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  HashTable& operator=(const HashTable&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  HashTable& operator=(HashTable&&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator==(const HashTable&) = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) = delete;

protected:

  // Default constructor
  HashTable();

  // Copy constructor
  HashTable(const HashTable&);

  // Move constructor
  HashTable(HashTable&&) noexcept;

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  unsigned long HashKey(const Data&) const;

  // RoundTableSize
  unsigned long RoundTableSize(unsigned long);

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
