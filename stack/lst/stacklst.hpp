
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, 
                 virtual protected List<Data>{
  // Must extend Stack<Data>,
  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;

  using List<Data>::size;
  using List<Data>::head;
  using List<Data>::tail;

public:

  // Default constructor
  // StackLst() specifier;
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a TraversableContainer
  StackLst(const TraversableContainer<Data>&);
  // StackLst(argument) specifiers; // A stack obtained from a MappableContainer
  StackLst(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);
  StackLst(const StackLst&);

  // Move constructor
  // StackLst(argument);
  StackLst(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;
  virtual ~StackLst();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackLst& operator=(const StackLst&);

  // Move assignment
  // type operator=(argument);
  StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const StackLst&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  const Data& Top() const override;
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override;
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  void Pop() override;
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override;
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  void Push(const Data&) override;
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  void Push(Data&&) noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
