
namespace lasd {

  /* ************************************************************************** */

  // NODEVEC

  // Specific constructors
  template <typename Data>
  BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &data, unsigned long index, Vector<NodeVec *> *new_vector)
  {
    element = data;
    current_node_index = index;
    vector_node_pointer = new_vector;
  }

  template <typename Data>
  BinaryTreeVec<Data>::NodeVec::NodeVec(Data &data, unsigned long index, Vector<NodeVec *> *new_vector)
  {
    element = data;
    current_node_index = index;
    vector_node_pointer = new_vector;
  }

  // Specific member functions

  // Element() non mutable
  template <typename Data>
  const Data &BinaryTreeVec<Data>::NodeVec::Element() const noexcept
  {
    return element;
  }

  // Element() mutable
  template <typename Data>
  Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept
  {
    return element;
  }

  // isLeaf()
  template <typename Data>
  bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept
  {
    return !(HasLeftChild() || HasRightChild());
  }

  // HasLeftChild()
  template <typename Data>
  bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
  {
    return ((current_node_index * 2 + 1) < vector_node_pointer->Size());
  }

  // HasRightChild()
  template <typename Data>
  bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept
  {
    return ((current_node_index * 2 + 2) < vector_node_pointer->Size());
  }

  // LeftChild()
  template <typename Data>
  const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const
  {
    if (!HasLeftChild())
    {
      throw std::out_of_range("Left child does not exist");
    }

    return *(vector_node_pointer->operator[](current_node_index * 2 + 1));
  }

  // RightChild()
  template <typename Data>
  const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const
  {
    if (!HasRightChild())
    {
      throw std::out_of_range("Right child does not exist");
    }

    return *(vector_node_pointer->operator[](current_node_index * 2 + 2));
  }

  // Specific member functions from MutableNode

  // LeftChild()
  template <typename Data>
  typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild()
  {
    return const_cast<typename BinaryTreeVec<Data>::NodeVec&>(static_cast<const BinaryTreeVec<Data>::NodeVec*>(this)->LeftChild());
  }

  // RightChild()
  template <typename Data>
  typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild()
  {
    return const_cast<typename BinaryTreeVec<Data>::NodeVec&>(static_cast<const BinaryTreeVec<Data>::NodeVec*>(this)->RightChild());
  }

  /* ************************************************************************** */

  // BINARYTREEVEC

  // Specific constructors

  // A binary tree obtained from a TraversableContainer
  template <typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> &container)
  {
    if (container.Size() > 0)
    {
      size = container.Size();
      vector_tree_pointer = new Vector<NodeVec*>(size);
      unsigned long index = 0;

      container.Traverse([this, &index](const Data &data) 
      {
        NodeVec* vector_node = new NodeVec(data, index, vector_tree_pointer);
        vector_tree_pointer->operator[](index) = vector_node;
        index++; 
      });
    }
  }

  // A binary tree obtained from a MappableContainer
  template <typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&container)
  {
    if (container.Size() > 0)
    {
      size = container.Size();
      vector_tree_pointer = new Vector<NodeVec *>(size);
      unsigned long index = 0;

      container.Map([this, &index](Data &data) 
      {
        NodeVec* vector_node = new NodeVec(std::move(data), index, vector_tree_pointer);
        vector_tree_pointer->operator[](index) = vector_node;
        index++; 
      });
    }
  }

  // Copy constructor
  template <typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& binary_tree)
  {
    size = binary_tree.size;
    vector_tree_pointer = new Vector<NodeVec*>(size);

    for (unsigned long index = 0; index < size; index++)
    {
      NodeVec *temp_node = new NodeVec(binary_tree.vector_tree_pointer->operator[](index)->Element(), index, vector_tree_pointer);
      (*vector_tree_pointer)[index] = temp_node;
    }
  }

  // Move constructor
  template <typename Data>
  BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&binary_tree) noexcept
  {
    vector_tree_pointer = new Vector<NodeVec *>();
    std::swap(size, binary_tree.size);
    std::swap(vector_tree_pointer, binary_tree.vector_tree_pointer);
  }

  // Destructor
  template <typename Data>
  BinaryTreeVec<Data>::~BinaryTreeVec()
  {
    Clear();
    delete vector_tree_pointer;
    vector_tree_pointer = nullptr;
  }

  // Copy assignment
  template <typename Data>
  BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> &binary_tree)
  {
    if (binary_tree.size > 0)
    {
      BinaryTreeVec<Data> *temp_binary_tree = new BinaryTreeVec<Data>(binary_tree);
      std::swap(*temp_binary_tree, *this);
      delete temp_binary_tree;
    }
    else
    {
      Clear(); // se la size di binary_tree e' 0 svuota l'oggetto corrente
    }
    return *this;
  }

  // Move assignment
  template <typename Data>
  BinaryTreeVec<Data> &BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> &&binary_tree) noexcept
  {
    std::swap(size, binary_tree.size);
    std::swap(vector_tree_pointer, binary_tree.vector_tree_pointer);
    return *this;
  }

  // Comparison operators
  template <typename Data>
  bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data> &binary_tree) const noexcept
  {
    return BinaryTree<Data>::operator==(binary_tree);
  }

  template <typename Data>
  bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data> &binary_tree) const noexcept
  {
    return !(*this == binary_tree);
  }

  // Specific member functions (inherited from BinaryTree)
  template <typename Data>
  const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const 
  {
    if (size == 0)
    {
      throw std::length_error("BinaryTree is empty");
    }
    return *(vector_tree_pointer->operator[](0));
  }

  // Specific member function (inherited from MutableBinaryTree)
  template <typename Data>
  typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root()
  {
    return const_cast<typename BinaryTreeVec<Data>::NodeVec&>(static_cast<const BinaryTreeVec<Data>*>(this)->Root());
  }

  // Specific member function (inherited from ClearableContainer)
  template <typename Data>
  void BinaryTreeVec<Data>::Clear()
  {
    if (size > 0)
    {
      for (unsigned long index = 0; index < size; index++)
      {
        delete (*vector_tree_pointer)[index];
      }
      vector_tree_pointer->Clear();
      size = 0;
    }
  }

  // Specific member function (inherited from BreadthTraversableContainer)
  template <typename Data>
  void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const
  {
    for (unsigned long index = 0; index < size; index++)
    {
      fun(vector_tree_pointer->operator[](index)->Element());
    }
  }

  // Specific member function (inherited from BreadthMappableContainer)
  template <typename Data>
  void BinaryTreeVec<Data>::BreadthMap(MapFun fun)
  {
    for (unsigned long index = 0; index < size; index++)
    {
      fun(vector_tree_pointer->operator[](index)->Element());
    }
  } 

  /* ************************************************************************** */

}
