
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>,
                 virtual protected Vector<Data> {
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  unsigned long index = 0;
  using Vector<Data>::size;
  using Vector<Data>::Elements;
  

public:

  // Default constructor
  StackVec() : Vector<Data>(1){};

  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
  StackVec(const TraversableContainer<Data>&);

  // StackVec(argument) specifiers; // A stack obtained from a MappableContainer
  StackVec(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // StackVec(argument);
  StackVec(const StackVec&);

  // Move constructor
  // StackVec(argument);
  StackVec(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;
  virtual ~StackVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackVec& operator=(const StackVec&);

  // Move assignment
  // type operator=(argument);
  StackVec& operator=(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const StackVec&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const StackVec&) const noexcept;

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
  void Push(Data&&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  unsigned long Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

protected:

  // Auxiliary functions, if necessary!
  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
