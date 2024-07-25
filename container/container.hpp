
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ... 

protected:

  unsigned long size = 0;

  /* ************************************************************************ */

  // Default constructor
  // Container() specifiers;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete; // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  Container& operator=(Container&&) noexcept = delete; // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container&) const noexcept = delete; // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const Container&) const noexcept = delete; // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  virtual bool Empty() const noexcept { 
    return (size == 0);
  } 

  // type Size() specifiers; // (concrete function should not throw exceptions)
  virtual unsigned long Size() const noexcept {
    return size;
  }

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ClearableContainer& operator=(const ClearableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators

  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ClearableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer&) const noexcept = delete;
  
  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ResizableContainer& operator=(const ResizableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ResizableContainer& operator=(ResizableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ResizableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
  virtual void Resize(unsigned long new_size) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  inline virtual void Clear() override {
    Resize(0);
  }

};

/* ************************************************************************** */

}

#endif
