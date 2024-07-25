
namespace lasd {

  /* ************************************************************************** */

  // Specific constructors

  // A bst obtained from a TraversableContainer
  template <typename Data>
  BST<Data>::BST(const TraversableContainer<Data> &container)
  {
    container.Traverse([this](const Data &data)
      { 
        Insert(data); 
      }
    );
  }

  // A bst obtained from a MappableContainer
  template <typename Data>
  BST<Data>::BST(MappableContainer<Data> &&container)
  {
    container.Map([this](Data &data)
      { 
        Insert(std::move(data)); 
      }
    );
  }

  // Copy constructor
  template <typename Data>
  BST<Data>::BST(const BST<Data> &bst) : BinaryTreeLnk<Data>(bst) {}

  // Move constructor
  template <typename Data>
  BST<Data>::BST(BST<Data> &&bst) noexcept : BinaryTreeLnk<Data>(std::move(bst)) {}

  // Copy assignment
  template <typename Data>
  BST<Data> &BST<Data>::operator=(const BST &bst)
  {
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BST<Data> &BST<Data>::operator=(BST &&bst) noexcept
  {
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
  }

  // Comparison operators
  template <typename Data>
  bool BST<Data>::operator==(const BST<Data> &bst) const noexcept
  {
    if (size == bst.Size())
    {
      BTInOrderIterator<Data> it(*this);
      BTInOrderIterator<Data> other_it(bst);

      while (!it.Terminated())
      {
        if (*it != *other_it)
        {
          return false;
        }
        ++it;
        ++other_it;
      }

      return true;
    } 
    else 
    {
      return false;
    }
  }

  template <typename Data>
  bool BST<Data>::operator!=(const BST &bst) const noexcept
  {
    return !(*this == bst);
  }

  // Specific member functions

  // Min()
  template <typename Data>
  const Data &BST<Data>::Min() const
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }

    return FindPointerToMin(root)->element;
  }

  // MinNRemove()
  template <typename Data>
  Data BST<Data>::MinNRemove()
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }

    return DataNDelete(DetachMin(root));
  }

  // RemoveMin()
  template <typename Data>
  void BST<Data>::RemoveMin()
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }

    delete DetachMin(root);
  }

  // Max()
  template <typename Data>
  const Data &BST<Data>::Max() const
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }

    return FindPointerToMax(root)->element;
  }

  // MaxNRemove()
  template <typename Data>
  Data BST<Data>::MaxNRemove()
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }

    return DataNDelete(DetachMax(root));
  }

  // RemoveMax()
  template <typename Data>
  void BST<Data>::RemoveMax()
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }

    delete DetachMax(root);
  }

  // Predecessor()
  template <typename Data>
  const Data &BST<Data>::Predecessor(const Data &pred_data) const
  {
    const BST<Data>::NodeLnk *const *temp = FindPointerToPredecessor(root, pred_data);

    if (temp == nullptr)
    {
      throw std::length_error("Predecessor does not exist");
    }

    return (*temp)->element;
  }

  // PredecessorNRemove()
  template <typename Data>
  Data BST<Data>::PredecessorNRemove(const Data &pred_data)
  {
    BST<Data>::NodeLnk **temp = FindPointerToPredecessor(root, pred_data);

    if (temp == nullptr)
    {
      throw std::length_error("Predecessor does not exist");
    }

    return DataNDelete(Detach(*temp));
  }

  // RemovePredecessor()
  template <typename Data>
  void BST<Data>::RemovePredecessor(const Data &pred_data)
  {

    BST<Data>::NodeLnk **temp = FindPointerToPredecessor(root, pred_data);

    if (temp == nullptr)
    {
      throw std::length_error("Predecessor does not exist");
    }

    delete Detach(*temp);
  }

  // Successor()
  template <typename Data>
  const Data &BST<Data>::Successor(const Data &succ_data) const
  {
    const BST<Data>::NodeLnk *const *temp = FindPointerToSuccessor(root, succ_data);

    if (temp == nullptr)
    {
      throw std::length_error("Successor does not exist");
    }

    return (*temp)->element;
  }

  // SuccessorNRemove()
  template <typename Data>
  Data BST<Data>::SuccessorNRemove(const Data &succ_data)
  {
    BST<Data>::NodeLnk **temp = FindPointerToSuccessor(root, succ_data);

    if (temp == nullptr)
    {
      throw std::length_error("Successor does not exist");
    }

    return DataNDelete(Detach(*temp));
  }

  // RemoveSuccessor()
  template <typename Data>
  void BST<Data>::RemoveSuccessor(const Data &succ_data)
  {

    BST<Data>::NodeLnk **temp = FindPointerToSuccessor(root, succ_data);

    if (temp == nullptr)
    {
      throw std::length_error("Successor does not exist");
    }

    delete Detach(*temp);
  }

  // Specific member function (inherited from BinaryTree)
  template <typename Data>
  const BST<Data>::NodeLnk &BST<Data>::Root() const
  {
    if (root == nullptr)
    {
      throw std::length_error("BST is empty");
    }
    return *root;
  }

  // Specific member functions (inherited from DictionaryContainer)

  // Insert() copy of the value
  template <typename Data>
  bool BST<Data>::Insert(const Data &data)
  {
    BST<Data>::NodeLnk *& insert_pointer = FindPointerTo(root, data);

    if (insert_pointer == nullptr)
    {
      insert_pointer = new BST<Data>::NodeLnk(data);
      ++size;
      return true;
    }
    else
    {
      return false;
    }
  }

  // Insert() move of the value
  template <typename Data>
  bool BST<Data>::Insert(Data &&data) 
  {
    BST<Data>::NodeLnk *& insert_pointer = FindPointerTo(root, data);

    if (insert_pointer == nullptr)
    {
      insert_pointer = new BST<Data>::NodeLnk(std::move(data));
      ++size;
      return true;
    }
    else
    {
      return false;
    }
  }

  // Remove()
  template <typename Data>
  bool BST<Data>::Remove(const Data &data) 
  {
    BST<Data>::NodeLnk *& remove_pointer = FindPointerTo(root, data);

    if (remove_pointer != nullptr)
    {
      delete Detach(remove_pointer);
      return true;
    }
    else
    {
      return false;
    }
  }

  // Specific member functions (inherited from TestableContainer)

  // Exist()
  template <typename Data>
  bool BST<Data>::Exists(const Data &data) const noexcept
  {
    return (FindPointerTo(root, data) != nullptr);
  }

  // View()
  template <typename Data>
  void BST<Data>::ViewTree() const
  {
    if (Size() == 0)
    {
      throw std::length_error("BST is empty!");
    }

    std::cout << "Size: " << Size() << "\n";
    std::cout << "Root: " << Root().Element() << "\n\n";
    std::cout << "Min: " << Min() << "\n";
    std::cout << "Max: " << Max() << "\n\n";

    BinaryTree<Data>::PrintNodes();

    BST &tree = const_cast<BST &>(*this);

    std::cout << "\n\nPreOrder visit:\n";
    tree.PreOrderTraverse([](const Data &data) { std::cout << data << " "; });

    std::cout << "\n\nPostOrder Visit:\n";
    tree.PostOrderTraverse([](const Data &data) { std::cout << data << " "; });

    std::cout << "\n\nInOrder visit:\n";
    tree.InOrderTraverse([](const Data &data) { std::cout << data << " "; });

    std::cout << "\n\nBreadth Visit:\n";
    tree.BreadthMap([](const Data &data) { std::cout << data << " "; });

  }

  // Auxiliary functions

  // DataNDelete()
  template <typename Data>
  Data BST<Data>::DataNDelete(BST<Data>::NodeLnk *node)
  {
    Data data;
    std::swap(data, node->element);
    delete node;

    return data;
  }

  // Detach()
  template <typename Data>
  typename BST<Data>::NodeLnk *BST<Data>::Detach(NodeLnk *&node) noexcept
  {
    if (node != nullptr)
    {
      if (node->left_child == nullptr)
      {
        return Skip2Right(node);
      }
      else if (node->right_child == nullptr)
      {
        return Skip2Left(node);
      }
      else
      {
        NodeLnk *detach_ptr = DetachMax(node->left_child);
        std::swap(node->element, detach_ptr->element);
        return detach_ptr;
      }
    }
    else
    {
      return nullptr;
    }
  }

  // DetachMin()
  template <typename Data>
  typename BST<Data>::NodeLnk *BST<Data>::DetachMin(NodeLnk *&node) noexcept
  {
    return Skip2Right(FindPointerToMin(node));
  }

  // DetachMax()
  template <typename Data>
  typename BST<Data>::NodeLnk *BST<Data>::DetachMax(NodeLnk *&node) noexcept
  {
    return Skip2Left(FindPointerToMax(node));
  }

  // Skip2Left()
  template <typename Data>
  typename BST<Data>::NodeLnk *BST<Data>::Skip2Left(NodeLnk *&node) noexcept
  {
    NodeLnk *skip_left_ptr = nullptr;

    if (node != nullptr)
    {
      std::swap(skip_left_ptr, node->left_child);
      std::swap(skip_left_ptr, node);
      --size;
    }

    return skip_left_ptr;
  }

  // Skip2Right()
  template <typename Data>
  typename BST<Data>::NodeLnk *BST<Data>::Skip2Right(NodeLnk *&node) noexcept
  {
    NodeLnk *skip_right_ptr = nullptr;

    if (node != nullptr)
    {
      std::swap(skip_right_ptr, node->right_child);
      std::swap(skip_right_ptr, node);
      --size;
    }

    return skip_right_ptr;
  }

  // FindPointerToMin() mutable
  template <typename Data>
  BST<Data>::NodeLnk *&BST<Data>::FindPointerToMin(BST<Data>::NodeLnk *&node) noexcept
  {
    return const_cast<BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
  }

  // FindPointerToMin() unmutable
  template <typename Data>
  const typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMin(const NodeLnk *const &node) const noexcept
  {
    if (node != nullptr)
    {
      if (node->HasLeftChild())
      {
        return FindPointerToMin(node->left_child);
      }
    }

    return node;
  }

  // FindPointerToMax() mutable
  template <typename Data>
  BST<Data>::NodeLnk *&BST<Data>::FindPointerToMax(BST<Data>::NodeLnk *&node) noexcept
  {
    return const_cast<BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
  }

  // FindPointerToMax() unmutable
  template <typename Data>
  const typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerToMax(const NodeLnk *const &node) const noexcept
  {
    if (node != nullptr)
    {
      if (node->HasRightChild())
      {
        return FindPointerToMax(node->right_child);
      }
    }

    return node;
  }

  // FindPointerTo() mutable
  template <typename Data>
  BST<Data>::NodeLnk *&BST<Data>::FindPointerTo(BST<Data>::NodeLnk *&node, const Data &data) noexcept
  {
    return const_cast<BST<Data>::NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, data));
  }

  // FindPointerTo() unmutable
  template <typename Data>
  const typename BST<Data>::NodeLnk *const &BST<Data>::FindPointerTo(const NodeLnk *const &node, const Data &data) const noexcept
  {
    if (node != nullptr)
    {
      if (node->Element() < data)
      {
        return FindPointerTo(node->right_child, data);
      }

      if (node->Element() > data)
      {
        return FindPointerTo(node->left_child, data);
      }
    }

    return node;
  }

  // FindPointerToPredecessor() mutable
  template <typename Data>
  BST<Data>::NodeLnk **BST<Data>::FindPointerToPredecessor(BST<Data>::NodeLnk *&node, const Data &data) noexcept
  {
    return const_cast<NodeLnk **>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, data));
  }

  // FindPointerToPredecessor() unmutable
  template <typename Data>
  const typename BST<Data>::NodeLnk *const *BST<Data>::FindPointerToPredecessor(const NodeLnk *const &node, const Data &data) const noexcept
  {
    if (node == nullptr)
    {
      return nullptr;
    }

    const NodeLnk *const *current_ptr = &node;
    const NodeLnk *const *left_ptr = nullptr;

    while (true)
    {
      if ((*current_ptr)->Element() < data)
      {

        if ((*current_ptr)->HasRightChild())
        {
          left_ptr = current_ptr;
          current_ptr = &((*current_ptr)->right_child);
        }
        else
        {
          return current_ptr;
        }

      }
      else if ((*current_ptr)->Element() >= data)
      {

        if ((*current_ptr)->HasLeftChild())
        {
          current_ptr = &((*current_ptr)->left_child);
        }
        else
        {
          return left_ptr;
        }

      }
    }
  }

  // FindPointerToSuccessor() mutable
  template <typename Data>
  BST<Data>::NodeLnk **BST<Data>::FindPointerToSuccessor(BST<Data>::NodeLnk *&node, const Data &data) noexcept
  {
    return const_cast<NodeLnk **>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
  }

  // FindPointerToSuccessor() unmutable
  template <typename Data>
  const typename BST<Data>::NodeLnk *const *BST<Data>::FindPointerToSuccessor(const NodeLnk *const &node, const Data &data) const noexcept
  {
    if (node == nullptr)
    {
      return nullptr;
    }

    const NodeLnk *const *current_ptr = &node;
    const NodeLnk *const *right_ptr = nullptr;

    while (true)
    {
      if ((*current_ptr)->Element() <= data)
      {

        if ((*current_ptr)->HasRightChild())
        {
          current_ptr = &((*current_ptr)->right_child);
        }
        else
        {
          return right_ptr;
        }

      }
      else if ((*current_ptr)->Element() > data)
      {

        if ((*current_ptr)->HasLeftChild())
        {
          right_ptr = current_ptr;
          current_ptr = &((*current_ptr)->left_child);
        }
        else
        {
          return current_ptr;
        }

      }
    }
  }

  /* ************************************************************************** */

}
