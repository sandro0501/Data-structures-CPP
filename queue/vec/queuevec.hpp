
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, 
                 virtual protected Vector<Data> {
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::Elements;
  unsigned long head = 0;
  unsigned long tail = 0;

public:

  // Default constructor
  // QueueVec() specifier;
  QueueVec() : Vector<Data>::Vector(2) {};

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueVec(const TraversableContainer<Data>&);
  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
  QueueVec(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  QueueVec(const QueueVec<Data>&);

  // Move constructor
  // QueueVec(argument);
  QueueVec(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  ~QueueVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec& operator=(const QueueVec&);

  // Move assignment
  // type operator=(argument);
  QueueVec& operator=(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueVec<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  const Data& Head() const override;
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  bool Empty() const noexcept override;

  // type Size() specifiers; // Override Container member
  unsigned long Size() const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() noexcept override;

protected:

  // Auxiliary functions, if necessary!
  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
