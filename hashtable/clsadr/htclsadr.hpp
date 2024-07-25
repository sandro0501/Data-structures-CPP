
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../bst/bst.hpp"
#include "../../binarytree/binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> {
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

  Vector<BST<Data>> table_vector;

  // ...

public:

  // Default constructor
  // HashTableClsAdr() specifiers;
  HashTableClsAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(unsigned long);
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const TraversableContainer<Data>&);
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(unsigned long, const TraversableContainer<Data>&);
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableClsAdr(MappableContainer<Data>&&);
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableClsAdr(unsigned long, MappableContainer<Data>&&); 

  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr&);

  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(HashTableClsAdr&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(const HashTableClsAdr&);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(HashTableClsAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const HashTableClsAdr&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const HashTableClsAdr&) const noexcept;

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

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
