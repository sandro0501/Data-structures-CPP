
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::size;

  // ...

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  struct NodeLnk : virtual MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    // ...
    Data element;
    NodeLnk* left_child = nullptr;
    NodeLnk* right_child = nullptr;

    // Default constructor
    NodeLnk() = default;

    // Specific constructors
    NodeLnk(const Data&); //Copy specific element data
    NodeLnk(Data&&) noexcept; //Move specific element data

    NodeLnk(const NodeLnk&); //Copy specific node
    NodeLnk(NodeLnk&&) noexcept; //Move specific node

    // Destructor
    ~NodeLnk();

    // Copy assignment
    NodeLnk& operator=(const NodeLnk&);

    // Move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    // Comparison operators
    bool operator==(const NodeLnk&) const noexcept;
    bool operator!=(const NodeLnk&) const noexcept;
    
    // Specific member functions
    const Data& Element() const noexcept override;
    Data& Element() noexcept override;

    bool IsLeaf() const noexcept override;

    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    virtual const NodeLnk& LeftChild() const override;
    virtual const NodeLnk& RightChild() const override;

    // Specific member functions from MutableNode
    virtual NodeLnk& LeftChild() override;
    virtual NodeLnk& RightChild() override;

  };

  NodeLnk* root = nullptr;
  NodeLnk& CopyBinaryTree(const NodeLnk&);

public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(const TraversableContainer<Data>&);
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk<Data>&);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(const BinaryTreeLnk<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  virtual const NodeLnk& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  virtual NodeLnk& Root() override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
