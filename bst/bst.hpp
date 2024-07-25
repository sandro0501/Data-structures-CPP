
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer,
            virtual public DictionaryContainer<Data>, 
            virtual public BinaryTree<Data>, 
            virtual public BinaryTreeLnk<Data> {
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;

  using typename BinaryTreeLnk<Data>::NodeLnk;

public:

  // Default constructor
  // BST() specifiers;
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a TraversableContainer
  BST(const TraversableContainer<Data>&);
  // BST(argument) specifiers; // A bst obtained from a MappableContainer
  BST(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST&);

  // Move constructor
  // BST(argument) specifiers;
  BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST& operator=(const BST&);

  // Move assignment
  // type operator=(argument) specifiers;
  BST& operator=(BST&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BST&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual const Data& Min() const;
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data MinNRemove();
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual void RemoveMin();

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual const Data& Max() const;
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data MaxNRemove();
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual void RemoveMax();

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual const Data& Predecessor(const Data&) const;
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual Data PredecessorNRemove(const Data&);
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual void RemovePredecessor(const Data&);

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual const Data& Successor(const Data&) const;
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual Data SuccessorNRemove(const Data&); 
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual void RemoveSuccessor(const Data&);

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  // type Root(argument) specifiers; // Override BinaryTree member
  virtual const NodeLnk& Root() const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  bool Insert(const Data&) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  bool Insert(Data&&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  virtual bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer member
  using BinaryTreeLnk<Data>::Clear;

  /* ************************************************************************ */

  void ViewTree() const;

protected:

  // Auxiliary functions, if necessary!

  // type DataNDelete(argument) specifiers;
  virtual Data DataNDelete(NodeLnk*);

  // type Detach(argument) specifiers;
  virtual NodeLnk* Detach(NodeLnk*&) noexcept;

  // type DetachMin(argument) specifiers;
  virtual NodeLnk* DetachMin(NodeLnk*&) noexcept;
  // type DetachMax(argument) specifiers;
  virtual NodeLnk* DetachMax(NodeLnk*&) noexcept;

  // type Skip2Left(argument) specifiers;
  virtual NodeLnk* Skip2Left(NodeLnk*&) noexcept;
  // type Skip2Right(argument) specifiers;
  virtual NodeLnk* Skip2Right(NodeLnk*&) noexcept;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  virtual NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
  virtual const NodeLnk * const & FindPointerToMin(const NodeLnk * const &) const noexcept;

  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions
  virtual NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
  virtual const NodeLnk * const & FindPointerToMax(const NodeLnk * const &) const noexcept;
  
  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions
  virtual NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
  virtual const NodeLnk * const & FindPointerTo(const NodeLnk * const &, const Data &) const noexcept;

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  virtual NodeLnk ** FindPointerToPredecessor(NodeLnk *&, const Data&) noexcept;
  virtual const NodeLnk * const * FindPointerToPredecessor(const NodeLnk * const &, const Data &) const noexcept;

  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions
  virtual NodeLnk ** FindPointerToSuccessor(NodeLnk *&, const Data&) noexcept;
  virtual const NodeLnk * const * FindPointerToSuccessor(const NodeLnk * const &, const Data &) const noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
