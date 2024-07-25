
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  DictionaryContainer& operator=(const DictionaryContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  DictionaryContainer& operator=(DictionaryContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const DictionaryContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const DictionaryContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  virtual bool Insert(const Data&) = 0;

  // type Insert(argument) specifiers; // Move of the value
  virtual bool Insert(Data&&) = 0;

  // type Remove(argument) specifiers;
  virtual bool Remove(const Data&) = 0;

  // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
  virtual bool InsertAll(const TraversableContainer<Data>&);

  // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
  virtual bool InsertAll(MappableContainer<Data>&&);

  // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed
  virtual bool RemoveAll(const TraversableContainer<Data>&);

  // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
  virtual bool InsertSome(const TraversableContainer<Data>&);

  // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
  virtual bool InsertSome(MappableContainer<Data>&&);

  // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed
  virtual bool RemoveSome(const TraversableContainer<Data>&);

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
