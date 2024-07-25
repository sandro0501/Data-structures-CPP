
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::table_size;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::prime;
  using HashTable<Data>::hash_function;
  using HashTable<Data>::HashKey;

  // ...
  Vector<Data> table_vector;
  Vector<char> flags_vector = Vector<char>(16);
  /*
    flags_vector
    E = EMPTY
    O = OCCUPED
    D = DELETED
  */

public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  HashTableOpnAdr(unsigned long);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(const TraversableContainer<Data> &);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(unsigned long, const TraversableContainer<Data> &);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableOpnAdr(MappableContainer<Data> &&);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(unsigned long, MappableContainer<Data> &&);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr &);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(HashTableOpnAdr &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;
  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr& operator=(const HashTableOpnAdr&); 

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const HashTableOpnAdr&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const HashTableOpnAdr&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(const Data&) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  virtual bool Insert(Data&&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  virtual bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  virtual bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  virtual void Resize(const unsigned long) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  void Clear() override;


  void PrintHT() const;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  virtual unsigned long HashKey(Data, unsigned long) const;

  // type Find(argument) specifiers;
  virtual unsigned long Find(Data, unsigned long) const;

  // type FindEmpty(argument) specifiers;
  virtual unsigned long FindEmpty(Data) const;

  // Expand()
  virtual void Expand();

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
