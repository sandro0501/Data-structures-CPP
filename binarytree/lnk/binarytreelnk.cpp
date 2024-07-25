#include "../../queue/vec/queuevec.hpp"
#include "../../vector/vector.hpp"
#include "binarytreelnk.hpp"

namespace lasd {

  /* ************************************************************************** */

  // NODELNK

  // Specific constructors

  // Copy specific element data
  template <typename Data>
  BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data &value)
  {
    element = value;
    left_child = nullptr;
    right_child = nullptr;
  }

  // Move specific element data
  template <typename Data>
  BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data &&value) noexcept
  {
    element = std::move(value);
    left_child = nullptr;
    right_child = nullptr;
  }

  // Copy specific node
  template <typename Data>
  BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk &node)
  {
    if (node != nullptr)
    {
      element = node.element;
      left_child = node.left_child;
      right_child = node.right_child;
    }
  }

  // Move specific node
  template <typename Data>
  BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk &&node) noexcept
  {
    if (node != nullptr)
    {
      std::swap(element, node.element);
      std::swap(left_child, node.left_child);
      std::swap(right_child, node.right_child);
    }
  }

  // Destructor
  template <typename Data>
  BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
  {
    delete left_child;
    delete right_child;
  }

  // Copy assignment
  template <typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk &node)
  {
    element = node.element;
    left_child = node.left_child;
    right_child = node.right_child;
    return *this;
  }

  // Move assignment
  template <typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk &&node) noexcept
  {
    std::swap(element, node.element);
    std::swap(left_child, node.left_child);
    std::swap(right_child, node.right_child);
    return *this;
  }

  // Comparison operators
  template <typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk &node) const noexcept
  {
    return BinaryTree<Data>::Node::operator==(node);
  }

  template <typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk &node) const noexcept
  {
    return !(*this == node);
  }

  // Specific member functions

  // Element() non mutable
  template <typename Data>
  const Data &BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept
  {
    return element;
  }

  // Element() mutable
  template <typename Data>
  Data &BinaryTreeLnk<Data>::NodeLnk::Element() noexcept
  {
    return element;
  }

  // isLeaf()
  template <typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept
  {
    return (!(HasLeftChild() || HasRightChild()));
  }

  // HasLeftChild()
  template <typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept
  {
    return (left_child != nullptr);
  }

  // HasRightChild()
  template <typename Data>
  bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept
  {
    return (right_child != nullptr);
  }

  // LeftChild()
  template <typename Data>
  const typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const
  {
    if (left_child == nullptr)
    {
      throw std::out_of_range("Left child does not exist");
    }
    return *left_child;
  }

  // RightChild()
  template <typename Data>
  const typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const
  {
    if (right_child == nullptr)
    {
      throw std::out_of_range("Right child does not exist");
    }
    return *right_child;
  }

  // Specific member functions from MutableNode

  // LeftChild()
  template <typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild()
  {
    //return const_cast<typename BinaryTreeLnk<Data>::Node&>(static_cast<const typename BinaryTreeLnk<Data>::Node *>(this)->LeftChild());
    return const_cast<typename BinaryTreeLnk<Data>::NodeLnk&>(static_cast<const BinaryTreeLnk<Data>::NodeLnk*>(this)->LeftChild());
  }

  // RightChild()
  template <typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild()
  {
    return const_cast<typename BinaryTreeLnk<Data>::NodeLnk&>(static_cast<const BinaryTreeLnk<Data>::NodeLnk*>(this)->RightChild());
  }

  // CopyBinaryTree
  template <typename Data>
  struct BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::CopyBinaryTree(const BinaryTreeLnk<Data>::NodeLnk &copy_node)
  {

    NodeLnk *temp_node = new NodeLnk(copy_node.Element());
    if (copy_node.HasLeftChild())
    {
      temp_node->left_child = &(CopyBinaryTree(copy_node.LeftChild()));
    }
    if (copy_node.HasRightChild())
    {
      temp_node->right_child = &(CopyBinaryTree(copy_node.RightChild()));
    }
    return *temp_node;
  }

  /* ************************************************************************** */

  // BINARYTREELNK

  // Specific constructors

  // A binary tree obtained from a TraversableContainer
  template <typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> &container)
  {
    size = container.Size();

    if (size > 0)
    {
      QueueVec<BinaryTreeLnk<Data>::NodeLnk *> queue;
      bool left_check = true;
      container.Traverse([this, &queue, &left_check](const Data &data)
      {
        NodeLnk* temp_node = new NodeLnk(data);
          
        if (queue.Empty())
        {
          queue.Enqueue(temp_node);
          root = temp_node;
        } 
        else 
        {
          queue.Enqueue(temp_node);
          if (left_check) 
          {
            queue.Head()->left_child = temp_node;
            left_check = false;
          } 
          else 
          {
            queue.Head()->right_child = temp_node;
            left_check = true;
            queue.Dequeue();
          }
        } 
      });
    }
  }

  // A binary tree obtained from a MappableContainer
  template <typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> &&container) 
  {
    size = container.Size();

    if (size > 0)
    {
      QueueVec<BinaryTreeLnk<Data>::NodeLnk *> queue;
      bool left_check = true;
      container.Map([this, &queue, &left_check](Data &data)
      {
        NodeLnk* temp_node = new NodeLnk(std::move(data));
          
        if (queue.Empty())
        {
          queue.Enqueue(temp_node);
          root = temp_node;
        } 
        else 
        {
          queue.Enqueue(temp_node);
          if (left_check) 
          {
            queue.Head()->left_child = temp_node;
            left_check = false;
          } 
          else 
          {
            queue.Head()->right_child = temp_node;
            left_check = true;
            queue.Dequeue();
          }
        } 
      });
    }

  }

  // Copy constructor
  template <typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data> &copy_tree)
  {
    size = copy_tree.Size();
    if (size > 0)
    {
      root = &(CopyBinaryTree(copy_tree.Root()));
    }
  }

  // Move constructor
  template <typename Data>
  BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data> &&tree) noexcept
  {
    if (tree.Size() > 0)
    {
      std::swap(root, tree.root);
      std::swap(size, tree.size);
    }
  }

  // Destructor
  template <typename Data>
  BinaryTreeLnk<Data>::~BinaryTreeLnk()
  {
    delete root;
  }

  // Copy assignment
  template <typename Data>
  BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> &tree)
  {
    if (tree.size > 0)
    {
      BinaryTreeLnk<Data> *temp_tree = new BinaryTreeLnk<Data>(tree);
      std::swap(*temp_tree, *this);
      delete temp_tree;
    } 
    else 
    {
      Clear();
    }
    return *this;
  }

  // Move assignment
  template <typename Data>
  BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> &&tree) noexcept
  {
    std::swap(root, tree.root);
    std::swap(size, tree.size);
    return *this;
  }

  // Comparison operators
  template <typename Data>
  bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data> &tree) const noexcept
  {
    return BinaryTree<Data>::operator==(tree);
  }

  template <typename Data>
  bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data> &tree) const noexcept
  {
    return !(*this == tree);
  }

  // Specific member functions (inherited from BinaryTree)
  template <typename Data>
  const typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const 
  {
    if (root == nullptr)
    {
      throw std::length_error("BinaryTree is empty");
    }
    return *root;
  }

  // Specific member function (inherited from MutableBinaryTree)
  template <typename Data>
  typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root()
  {
    return const_cast<typename BinaryTreeLnk<Data>::NodeLnk&>(static_cast<const BinaryTreeLnk<Data>*>(this)->Root());
  }

  // Specific member function (inherited from ClearableContainer)
  template <typename Data>
  void BinaryTreeLnk<Data>::Clear()
  {
    delete root;
    root = nullptr;
    size = 0;
  }

  /* ************************************************************************** */

}
