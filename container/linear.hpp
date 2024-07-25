
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>,
                        virtual public PostOrderMappableContainer<Data> {
  // Must extend PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  LinearContainer& operator=(const LinearContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  LinearContainer& operator=(LinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator==(const LinearContainer&) const noexcept;
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual const Data& operator[](unsigned long) const = 0;
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](unsigned long) = 0;

  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Front() const;
  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Front();

  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual const Data& Back() const;
  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Back();

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(argument) specifiers; // Override TraversableContainer member
  inline virtual void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member
  inline virtual void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member
  inline virtual void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline virtual void Map(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline virtual void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline virtual void PostOrderMap(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {
  // Must extend LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;
  using LinearContainer<Data>::operator[];

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  SortableLinearContainer& operator=(const SortableLinearContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not be possible.
  SortableLinearContainer& operator=(SortableLinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator==(const SortableLinearContainer&) const noexcept;
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(const SortableLinearContainer&) const noexcept;

  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;
  virtual void Sort() noexcept;

protected:

  // Auxiliary member functions

  void QuickSort(unsigned long p, unsigned long r) noexcept;
  unsigned long Partition(unsigned long p, unsigned long r) noexcept;
};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
