
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...

public: 
  
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  using BinaryTree<Data>::size;

  struct NodeVec : virtual MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:
    // ...
    Data element;
    unsigned long current_node_index;
    Vector<NodeVec*>* vector_node_pointer = nullptr; // puntatore al vettore che contiene i puntatori ai figli del nodo

    // Default constructor
    NodeVec() = default;

    // Specific constructors
    NodeVec(const Data&, unsigned long, Vector<NodeVec*>*);
    NodeVec(Data&, unsigned long, Vector<NodeVec*>*);

    // Destructor
    virtual ~NodeVec() = default;

    // Specific member functions
    const Data& Element() const noexcept override;
    Data& Element() noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    virtual const NodeVec& LeftChild() const override;
    virtual const NodeVec& RightChild() const override;
    
    // Specific member functions from MutableNode
    virtual NodeVec& LeftChild() override;
    virtual NodeVec& RightChild() override;

  };

  Vector<NodeVec*>* vector_tree_pointer = nullptr;  // puntatore al vettore dei nodi che contiene i puntatori ai nodi dell'albero

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(const TraversableContainer<Data>&);
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator=(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeVec<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BinaryTreeVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  virtual const NodeVec& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  virtual NodeVec& Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  void BreadthTraverse(TraverseFun) const override;


  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  using typename MappableContainer<Data>::MapFun;

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
