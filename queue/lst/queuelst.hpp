
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>,
                 virtual protected List<Data> {
  // Must extend Queue<Data>,
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
  // QueueLst() specifier;
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueLst(const TraversableContainer<Data>&);
  // QueueLst(argument) specifiers; // A stack obtained from a MappableContainer
  QueueLst(MappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);
  QueueLst(const QueueLst<Data>&);

  // Move constructor
  // QueueLst(argument);
  QueueLst(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueLst& operator=(const QueueLst<Data>&);

  // Move assignment
  // type operator=(argument);
  QueueLst& operator=(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueLst<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const QueueLst<Data>&) const noexcept;

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

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
