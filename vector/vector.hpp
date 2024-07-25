
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer, 
               virtual public LinearContainer<Data> {
  // Must extend ResizableContainer,
  //             LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

  Data* Elements = nullptr;

  // ...

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; // A vector with a given initial dimension
  Vector(const unsigned long);
  // Vector(argument) specifiers; // A vector obtained from a TraversableContainer
  Vector(const TraversableContainer<Data>&);
  // Vector(argument) specifiers; // A vector obtained from a MappableContainer
  Vector(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;
  Vector(const Vector&);

  // Move constructor
  // Vector(argument) specifiers;
  Vector(Vector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  Vector& operator=(const Vector&);

  // Move assignment
  // type operator=(argument) specifiers;
  Vector& operator=(Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const Vector&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const Vector&) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member
  void Resize(const unsigned long) override;

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

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data>,
                       virtual public SortableLinearContainer<Data> {
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  // SortableVector() specifiers;
  SortableVector() = default;

  /* ************************************************************************ */

  // Specific constructors
  // SortableVector(argument) specifiers; // A vector with a given initial dimension
  SortableVector(const unsigned long);
  // SortableVector(argument) specifiers; // A vector obtained from a TraversableContainer
  SortableVector(const TraversableContainer<Data>&);
  // SortableVector(argument) specifiers; // A vector obtained from a MappableContainer
  SortableVector(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // SortableVector(argument) specifiers;
  SortableVector(const SortableVector &);

  // Move constructor
  // SortableVector(argument) specifiers;
  SortableVector(SortableVector &&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~SortableVector() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  SortableVector& operator=(const SortableVector&);

  // Move assignment
  // type operator=(argument) specifiers;
  SortableVector& operator=(SortableVector&&) noexcept;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
