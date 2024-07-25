
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer, 
             virtual public LinearContainer<Data>, 
             virtual public DictionaryContainer<Data>{
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using Container::size;

  struct Node {

    // Data
    Data info;
    Node* next_node = nullptr;

    /* ********************************************************************** */

    //Default constructor
    Node() = default;

    // Specific constructors
    Node(const Data& data);
    Node(Data&&) noexcept;

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node& node);

    // Move constructor
    Node(Node&& node) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

    /* ********************************************************************** */
  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  List(const TraversableContainer<Data>&);
  // List(argument) specifiers; // A list obtained from a MappableContainer
  List(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  List(const List&);

  // Move constructor
  // List(argument) specifiers;
  List(List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  List<Data>& operator=(const List<Data>&) noexcept;

  // Move assignment
  // type operator=(argument) specifiers;
  List<Data>& operator=(List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const List&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(const Data&);
  // type InsertAtFront(argument) specifier; // Move of the value
  void InsertAtFront(Data&&);

  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
  Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  void InsertAtBack(const Data&);
  // type InsertAtBack(argument) specifier; // Move of the value
  void InsertAtBack(Data&&);

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() noexcept override;

  /* ************************************************************************ */

  // type Insert(argument) specifier; // Copy of the value
  bool Insert(const Data&) override;
  // type Insert(argument) specifier; // Move of the value
  bool Insert(Data&&) override;
  // type Remove(argument) specifier;
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  const Data& operator[](const unsigned long) const override;
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const unsigned long) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  const Data& Front() const override;
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  Data& Front() override;

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  const Data& Back() const override;
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  Data& Back() override;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
  inline void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
  inline void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline void Map(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline void PostOrderMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

  //For TraversableContainer
  void PreOrderTraverse(TraverseFun, const Node*) const;
  void PostOrderTraverse(TraverseFun, const Node*) const;

  //For MappableContainer
  void PreOrderMap(MapFun, Node*);
  void PostOrderMap(MapFun, Node*);

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
