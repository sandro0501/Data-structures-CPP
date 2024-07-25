#include "binarytree.hpp"


namespace lasd {
/* ************************************************************************** */

  // NODE

  // Comparison operators

  // operator==
  template <typename Data>
  bool BinaryTree<Data>::Node::operator==(const Node &node) const noexcept
  {
    bool flag = true;

    if (Element() == node.Element())
    {
      if (HasLeftChild() && node.HasLeftChild())
      {
        flag = (LeftChild() == node.LeftChild());
      }
      else if (HasLeftChild() || node.HasLeftChild())
      {
        flag = false;
      }

      if (flag)
      {
        if (HasRightChild() && node.HasRightChild())
        {
          flag = (RightChild() == node.RightChild());
        }
        else if (HasRightChild() || node.HasRightChild())
        {
          flag = false;
        }
      }
    }
    else
    {
      flag = false;
    }

    return flag;
  }

  // operator!=
  template <typename Data>
  bool BinaryTree<Data>::Node::operator!=(const Node &node) const noexcept
  {
    return !(*this == node);
  }

  // Specific member functions

  // IsLeaf()
  template <typename Data>
  bool BinaryTree<Data>::Node::IsLeaf() const noexcept
  {
    return (!(HasLeftChild() || HasRightChild()));
  }

  /* ************************************************************************** */

  // BINARYTREE

  // Comparison operators

  // operator==
  template <typename Data>
  bool BinaryTree<Data>::operator==(const BinaryTree &tree) const noexcept
  {
    if (size != tree.size)
    {
      return false;
    }
    else if (size == 0)
    {
      return true;
    }
    else
    {
      return Root() == tree.Root();
    }
  }

  // operator!=
  template <typename Data>
  bool BinaryTree<Data>::operator!=(const BinaryTree &tree) const noexcept
  {
    return (!(*this == tree));
  }

  // Specific member function (inherited from TraversableContainer)

  // Traverse()
  template <typename Data>
  inline void BinaryTree<Data>::Traverse(TraverseFun fun) const
  {
    if (size > 0)
    {
      BinaryTree<Data>::PreOrderTraverse(fun);
    }
  }

  // Specific member function (inherited from PreOrderTraversableContainer)

  // PreOrderTraverse()
  template <typename Data>
  inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const
  {
    if (size > 0)
    {
      BinaryTree<Data>::PreOrderTraverse(fun, &Root());
    }
  }

  // Specific member function (inherited from PostOrderTraversableContainer)

  // PostOrderTraverse()
  template <typename Data>
  inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const
  {
    if (size > 0)
    {
      BinaryTree<Data>::PostOrderTraverse(fun, &Root());
    }
  }

  // Specific member function (inherited from InOrderTraversableContainer)

  // InOrderTraverse()
  template <typename Data>
  inline void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const
  {
    if (size > 0)
    {
      BinaryTree<Data>::InOrderTraverse(fun, &Root());
    }
  }

  // Specific member function (inherited from BreadthTraversableContainer)

  // BreadthTraverse()
  template <typename Data>
  inline void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const
  {
    if (size > 0)
    {
      BinaryTree<Data>::BreadthTraverse(fun, &Root());
    }
  }

  // Auxiliary functions

  // PreOrderTraverse() with node
  template <typename Data>
  void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node *node) const
  {
    if (node != nullptr)
    {
      fun(node->Element());

      if (node->HasLeftChild())
      {
        BinaryTree<Data>::PreOrderTraverse(fun, &(node->LeftChild()));
      }

      if (node->HasRightChild())
      {
        BinaryTree<Data>::PreOrderTraverse(fun, &(node->RightChild()));
      }
    }
  }

  // PostOrderTraverse() with node
  template <typename Data>
  void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node *node) const
  {
    if (node != nullptr)
    {
      if (node->HasLeftChild())
      {
        BinaryTree<Data>::PostOrderTraverse(fun, &(node->LeftChild()));
      }

      if (node->HasRightChild())
      {
        BinaryTree<Data>::PostOrderTraverse(fun, &(node->RightChild()));
      }

      fun(node->Element());
    }
  }

  // InOrderTraverse() with node
  template <typename Data>
  void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node *node) const
  {
    if (node != nullptr)
    {
      if (node->HasLeftChild())
      {
        BinaryTree<Data>::InOrderTraverse(fun, &(node->LeftChild()));
      }

      fun(node->Element());

      if (node->HasRightChild())
      {
        BinaryTree<Data>::InOrderTraverse(fun, &(node->RightChild()));
      }
    }
  }

  // BreadthTraverse() with node
  template <typename Data>
  void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node *node) const
  {
    if (size > 0)
    {
      QueueVec<const BinaryTree<Data>::Node *> queue;
      queue.Enqueue(node); // la radice 
      const BinaryTree<Data>::Node *temp_node = nullptr;

      while (!queue.Empty())
      {
        temp_node = queue.HeadNDequeue();

        fun(temp_node->Element());

        if (temp_node->HasLeftChild())
        {
          queue.Enqueue(&temp_node->LeftChild());
        }

        if (temp_node->HasRightChild())
        {
          queue.Enqueue(&temp_node->RightChild());
        }
      }
    }
  }

  /* ************************************************************************** */

  // MUTABLEBINARYTREE

  // Specific member function (inherited from MappableContainer)

  // Map()
  template <typename Data>
  inline void MutableBinaryTree<Data>::Map(MapFun fun) {
    if (size > 0)
    {
      MutableBinaryTree<Data>::PreOrderMap(fun);
    }
  } 

  // Specific member function (inherited from PreOrderMappableContainer)

  // PreOrderMap()
  template <typename Data>
  inline void MutableBinaryTree<Data>::PreOrderMap(MapFun fun)
  {
    if (size > 0)
    {
      MutableBinaryTree<Data>::PreOrderMap(fun, &Root());
    }
  }

  // Specific member function (inherited from PostOrderMappableContainer)

  // PostOrderMap()
  template <typename Data>
  inline void MutableBinaryTree<Data>::PostOrderMap(MapFun fun)
  {
    if (size > 0)
    {
      MutableBinaryTree<Data>::PostOrderMap(fun, &Root());
    }
  }

  // Specific member function (inherited from InOrderMappableContainer)

  // InOrderMap()
  template <typename Data>
  inline void MutableBinaryTree<Data>::InOrderMap(MapFun fun)
  {
    if (size > 0)
    {
      MutableBinaryTree<Data>::InOrderMap(fun, &Root());
    }
  }

  // Specific member function (inherited from BreadthMappableContainer)

  // BreadthMap()
  template <typename Data>
  inline void MutableBinaryTree<Data>::BreadthMap(MapFun fun)
  {
    if (size > 0)
    {
      MutableBinaryTree<Data>::BreadthMap(fun, &Root());
    }
  }

  // Auxiliary functions

  // PreOrderMap() with mutable node
  template <typename Data>
  void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode *node)
  {
    if(node != nullptr){

        fun(node->Element());

        if(node->HasLeftChild()){
            MutableBinaryTree<Data>::PreOrderMap(fun, &(node->LeftChild()));
        }

        if(node->HasRightChild()){
            MutableBinaryTree<Data>::PreOrderMap(fun, &(node->RightChild()));
        }
    }
  }

  // PostOrderMap() with mutable node
  template <typename Data>
  void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode *node)
  {
    if (node != nullptr)
    {
      if (node->HasLeftChild())
      {
        MutableBinaryTree<Data>::PostOrderMap(fun, &(node->LeftChild()));
      }

      if (node->HasRightChild())
      {
        MutableBinaryTree<Data>::PostOrderMap(fun, &(node->RightChild()));
      }

      fun(node->Element());
    }
  }

  // InOrderMap() with mutable node
  template <typename Data>
  void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode *node)
  {
    if (node != nullptr)
    {
      if (node->HasLeftChild())
      {
        MutableBinaryTree<Data>::InOrderMap(fun, &(node->LeftChild()));
      }

      fun(node->Element());

      if (node->HasRightChild())
      {
        MutableBinaryTree<Data>::InOrderMap(fun, &(node->RightChild()));
      }
    }
  }

  // BreadthMap() with mutable node
  template <typename Data>
  void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode *node)
  {
     if (size > 0)
    {
      QueueVec<MutableNode *> queue;
      queue.Enqueue(node); // la radice 
      MutableBinaryTree<Data>::MutableNode *temp_node = nullptr;

      while (!queue.Empty())
      {
        temp_node = queue.HeadNDequeue();

        fun(temp_node->Element());

        if (temp_node->HasLeftChild())
        {
          queue.Enqueue(&temp_node->LeftChild());
        }

        if (temp_node->HasRightChild())
        {
          queue.Enqueue(&temp_node->RightChild());
        }
      }
    }
  }

  // ViewTree()
  template <typename Data>
  void BinaryTree<Data>::ViewTree() const
  {
    if (size == 0)
    {
      throw std::length_error("Binary tree is empty!");
    }

    std::cout << "Size: " << size << "\n";
    std::cout << "Root: " << Root().Element() << "\n\n";
    PrintNodes();

    std::cout << "\n\nPreOrder visit:\n";
    PreOrderTraverse([](const Data &data) { std::cout << data << " "; });

    std::cout << "\n\nPostOrder visit:\n";
    PostOrderTraverse([](const Data &data) { std::cout << data << " "; });

    std::cout << "\n\nInOrder visit:\n";
    InOrderTraverse([](const Data &data) { std::cout << data << " "; });

    std::cout << "\n\nBreadth visit:\n";
    BreadthTraverse([](const Data &data){ std::cout << data << " "; });

  }

  // PrintNodes()
  template <typename Data>
  void BinaryTree<Data>::PrintNodes() const
  {
    if (size == 0)
    {
      throw std::length_error("Binary tree is empty!");
    }
    PrintNodes("", Root(), false); // parametri iniziali per la funzione ricorsiva di stampa
  }

  template <typename Data>
  void BinaryTree<Data>::PrintNodes(const std::string &prefisso, const typename BinaryTree<Data>::Node &node, bool is_left) const noexcept
  {
    std::cout << prefisso;
    std::cout << (is_left ? "├──" : "└──");
    std::cout << node.Element() << "\n";

    if (node.HasLeftChild())
    {
      PrintNodes(prefisso + (is_left ? "│   " : "    "), node.LeftChild(), true);
    }

    if (node.HasRightChild())
    {
      PrintNodes(prefisso + (is_left ? "│   " : "    "), node.RightChild(), false);
    }
  }

  /* ************************************************************************** */

  // BTPREORDERITERATOR 

  // Specific constructors
  template <typename Data>
  BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &binary_tree)
  {
    if (binary_tree.Size() > 0)
    {
      root = &(binary_tree.Root());
      current = &(binary_tree.Root());
    }
  }

  // Copy constructor
  template <typename Data>
  BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> &iterator)
  {
    root = iterator.root;
    current = iterator.current;
    stack = iterator.stack;
  }

  // Move constructor
  template <typename Data>
  BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);
  }

  // Copy assignment
  template <typename Data>
  BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &iterator)
  {
    BTPreOrderIterator<Data> *temp_iterator = new BTPreOrderIterator<Data>(iterator);
    std::swap(*temp_iterator, *this);
    delete (temp_iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);
  }

  // Specific member functions (inherited from MutableIterator)

  // operator*()
  template <typename Data>
  const Data &BTPreOrderIterator<Data>::operator*() const
  {
    if (Terminated())
    {
      throw std::out_of_range("PreOrderIterator is terminated");
    }
    else
    {
      return current->Element();
    }
  }

  // Terminated()
  template <typename Data>
  bool BTPreOrderIterator<Data>::Terminated() const noexcept
  {
    return (current == nullptr);
  }

  // Specific member functions (inherited from ForwardIterator)

  // operator++()
  template <typename Data>
  BTPreOrderIterator<Data> &BTPreOrderIterator<Data>::operator++()
  {
    if (Terminated())
    {
      throw std::out_of_range("PreOrderIterator is terminated");
    }
    else
    {

      if (current->HasRightChild())
      {
        stack.Push(&(current->RightChild()));
      }

      if (current->HasLeftChild())
      {
        stack.Push(&(current->LeftChild()));
      }

      if (!(stack.Empty()))
      {
        current = stack.TopNPop();
      }
      else
      {
        current = nullptr;
      }

      return (*this);
    }
  }

  // Specific member functions (inherited from ResettableIterator)

  // Reset()
  template <typename Data>
  void BTPreOrderIterator<Data>::Reset() noexcept
  {
      current = root;
      stack.Clear();
  }

  /* ************************************************************************** */

  // BTPREORDERMUTABLEITERATOR

  // Specific constructors
  template <typename Data>
  BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data> &binary_tree) : BTPreOrderIterator<Data>(binary_tree) {}

  // Copy constructor
  template <typename Data>
  BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator &iterator) : BTPreOrderIterator<Data>(iterator) {}

  // Move constructor
  template <typename Data>
  BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator &&iterator) noexcept : BTPreOrderIterator<Data>(std::move(iterator)) {}

  // Copy assignment
  template <typename Data>
  BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data> &iterator)
  {
    BTPreOrderIterator<Data>::operator=(iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data> &&iterator) noexcept
  {
    BTPreOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
  }

  // Specific member functions (inherited from MutableIterator)

  // operator*()
  template <typename Data>
  Data& BTPreOrderMutableIterator<Data>::operator*() 
  {
    if (current == nullptr)
    {
      throw std::out_of_range("PreOrderMutableIterator is terminated");
    }
    else
    {
      return const_cast<Data &>(current->Element());
    }
  }

  /* ************************************************************************** */

  // BTPOSTORDERITERATOR

  // Specific constructors
  template <typename Data>
  BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &binary_tree)
  {

    if (binary_tree.Size() > 0)
    {
      root = &binary_tree.Root();
      current = &binary_tree.Root();
    }

    if (current != nullptr)
    {
      BTPostOrderIterator<Data>::getMostLeftLeaf();
    }

  }

  // Copy constructor
  template <typename Data>
  BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data> &iterator)
  {
    root = iterator.root;
    current = iterator.current;
    stack = iterator.stack;
  }

  // Move constructor
  template <typename Data>
  BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);
  }

  // Copy assignment
  template <typename Data>
  BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> &iterator)
  {
    BTPostOrderIterator<Data> *temp_iterator = new BTPostOrderIterator<Data>(iterator);
    std::swap(*temp_iterator, *this);
    delete (temp_iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);
  }

  // Specific member functions (inherited from Iterator)

  // operator*()
  template <typename Data>
  const Data &BTPostOrderIterator<Data>::operator*() const
  {
    if (Terminated())
    {
      throw std::out_of_range("PostOrderIterator is terminated");
    }
    else
    {
      return current->Element();
    }
  }

  // Terminated()
  template <typename Data>
  bool BTPostOrderIterator<Data>::Terminated() const noexcept
  {
    return (current == nullptr);
  }

  // Specific member functions (inherited from ForwardIterator)

  // operator++()
  template <typename Data>
  BTPostOrderIterator<Data> &BTPostOrderIterator<Data>::operator++()
  {

    if (Terminated())
    {
      throw std::out_of_range("PostOrderIterator is terminated");
    }

    if (stack.Empty())
    {
      current = nullptr;
    }
    else
    {
       /*se il nodo al top dello stack ha un figlio sinistro 
       e il puntatore current si trova su questo figlio sinistro 
       e il nodo ha pure un figlio destro
       il puntatore current si sposta verso il figlio destro e cerca la foglia più a sinistra*/
      if ( (stack.Top()->HasLeftChild()) && (current == &(stack.Top()->LeftChild())) && (stack.Top()->HasRightChild()) )
      {
        current = &(stack.Top()->RightChild());
        BTPostOrderIterator<Data>::getMostLeftLeaf();
      }
      else
      {
        current = stack.TopNPop();
      }
    }

    return *this;

  }

  // Specific member functions (inherited from ResettableIterator)

  // Reset()
  template <typename Data>
  void BTPostOrderIterator<Data>::Reset() noexcept
  {
    current = root;
    stack.Clear();
    if (current != nullptr)
    {
      BTPostOrderIterator<Data>::getMostLeftLeaf();
    }
  }

  // Auxiliary functions

  // getMostLeftLeaf()
  template <typename Data>
  void BTPostOrderIterator<Data>::getMostLeftLeaf()
  {
    while (current->HasLeftChild())
    {
      stack.Push(current);
      current = &(current->LeftChild());
    }

    if (current->HasRightChild())
    {
      stack.Push(current);
      current = &(current->RightChild());
      getMostLeftLeaf();
    }
  }


  /* ************************************************************************** */

  // BTPOSTORDERMUTABLEITERATOR

  // Specific constructors
  template <typename Data>
  BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data> &binary_tree) : BTPostOrderIterator<Data>(binary_tree) {}

  // Copy constructor
  template <typename Data>
  BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator &iterator) : BTPostOrderIterator<Data>(iterator) {}

  // Move constructor
  template <typename Data>
  BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator &&iterator) noexcept : BTPostOrderIterator<Data>(std::move(iterator)) {}

  // Copy assignment
  template <typename Data>
  BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data> &iterator)
  {
    BTPostOrderIterator<Data>::operator=(iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data> &&iterator) noexcept
  {
    BTPostOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
  }

  // Specific member functions (inherited from MutableIterator)

  // operator*()
  template <typename Data>
  Data& BTPostOrderMutableIterator<Data>::operator*() 
  {
    if (current == nullptr)
    {
      throw std::out_of_range("PostOrderMutableIterator is terminated");
    }
    else
    {
      return const_cast<Data &>(current->Element());
    }
  }

  /* ************************************************************************** */

  // BTINORDERITERATOR

  // Specific constructors
  template <typename Data>
  BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &binary_tree)
  {
    if (binary_tree.Size() > 0)
    {
      root = &binary_tree.Root();
      current = &binary_tree.Root();
    }

    if (current != nullptr)
    {
      BTInOrderIterator<Data>::getMostLeftNode();
    }
  }

  // Copy constructor
  template <typename Data>
  BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data> &iterator)
  {
    root = iterator.root;
    current = iterator.current;
    stack = iterator.stack;
  }

  // Move constructor
  template <typename Data>
  BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);
  }

  // Copy assignment
  template <typename Data>
  BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> &iterator)
  {
    BTInOrderIterator<Data> *temp_iterator = new BTPostOrderIterator<Data>(iterator);
    std::swap(*temp_iterator, *this);
    delete (temp_iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(stack, iterator.stack);
  }

  // Specific member functions (inherited from Iterator)

  // operator*()
  template <typename Data>
  const Data &BTInOrderIterator<Data>::operator*() const
  {
    if (Terminated())
    {
      throw std::out_of_range("InOrderIterator is terminated");
    }
    else
    {
      return current->Element();
    }
  }

  // Terminated()
  template <typename Data>
  bool BTInOrderIterator<Data>::Terminated() const noexcept
  {
    return (current == nullptr);
  }

  // Specific member functions (inherited from ForwardIterator)

  // operator++()
  template <typename Data>
  BTInOrderIterator<Data> &BTInOrderIterator<Data>::operator++()
  {
    if (Terminated())
    {
      throw std::out_of_range("InOrderIterator is terminated");
    }

    if (current->HasRightChild())
    {
      current = &(current->RightChild());
      BTInOrderIterator<Data>::getMostLeftNode();
    }
    else
    {
      if (stack.Empty())
      {
        current = nullptr;
      }
      else
      {
        current = stack.TopNPop();
      }
    }
    return (*this);
  }

  // Specific member functions (inherited from ResettableIterator)

  // Reset()
  template <typename Data>
  void BTInOrderIterator<Data>::Reset() noexcept
  {
    current = root;
    stack.Clear();
    if (current != nullptr)
    {
      getMostLeftNode();
    }
  }

  // Auxiliary functions

  // getMostLeftNode()
  template <typename Data>
  void BTInOrderIterator<Data>::getMostLeftNode()
  {
    while (current->HasLeftChild())
    {
      stack.Push(current);
      current = &(current->LeftChild());
    }
  }

  /* ************************************************************************** */

  // BTINORDERMUTABLEITERATOR

  // Specific constructors
  template <typename Data>
  BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data> &binary_tree) : BTInOrderIterator<Data>(binary_tree) {}

  // Copy constructor
  template <typename Data>
  BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator &iterator) : BTInOrderIterator<Data>(iterator) {}

  // Move constructor
  template <typename Data>
  BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator &&iterator) noexcept : BTInOrderIterator<Data>(std::move(iterator)) {}

  // Copy assignment
  template <typename Data>
  BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data> &iterator)
  {
    BTInOrderIterator<Data>::operator=(iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data> &&iterator) noexcept
  {
    BTInOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
  }

  // Specific member functions (inherited from MutableIterator)

  // operator*()
  template <typename Data>
  Data& BTInOrderMutableIterator<Data>::operator*() 
  {
    if (current == nullptr)
    {
      throw std::out_of_range("InOrderMutableIterator is terminated");
    }
    else
    {
      return const_cast<Data &>(current->Element());
    }
  }

  /* ************************************************************************** */

  // BTBREADTHITERATOR

  // Specific constructors
  template <typename Data>
  BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &binary_tree)
  {
    if (binary_tree.Size() > 0)
    {
      root = &binary_tree.Root();
      current = &binary_tree.Root();
    }
  }

  // Copy constructor
  template <typename Data>
  BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data> &iterator)
  {
    root = iterator.root;
    current = iterator.current;
    queue = iterator.queue;
  }

  // Move constructor
  template <typename Data>
  BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(queue, iterator.queue);
  }

  // Copy assignment
  template <typename Data>
  BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> &iterator)
  {
    BTBreadthIterator<Data> *temp_iterator = new BTBreadthIterator<Data>(iterator);
    std::swap(*temp_iterator, *this);
    delete (temp_iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> &&iterator) noexcept
  {
    std::swap(root, iterator.root);
    std::swap(current, iterator.current);
    std::swap(queue, iterator.queue);
  }

  // Specific member functions (inherited from Iterator)

  // operator*()
  template <typename Data>
  const Data &BTBreadthIterator<Data>::operator*() const
  {
    if (Terminated())
    {
      throw std::out_of_range("BreadthIterator is terminated");
    }
    else
    {
      return current->Element();
    }
  }

  // Terminated()
  template <typename Data>
  bool BTBreadthIterator<Data>::Terminated() const noexcept
  {
    return (current == nullptr);
  }

  // Specific member functions (inherited from ForwardIterator)

  // operator++()
  template <typename Data>
  BTBreadthIterator<Data> &BTBreadthIterator<Data>::operator++()
  {

    if (Terminated())
    {
      throw std::out_of_range("BreadthIterator is terminated");
    }

    if (current->HasLeftChild())
    {
      queue.Enqueue(&(current->LeftChild()));
    }

    if (current->HasRightChild())
    {
      queue.Enqueue(&(current->RightChild()));
    }

    if (queue.Empty())
    {
      current = nullptr;
    }
    else
    {
      current = queue.HeadNDequeue();
    }
    return (*this);
  }

  // Specific member functions (inherited from ResettableIterator)

  // Reset()
  template <typename Data>
  void BTBreadthIterator<Data>::Reset() noexcept
  {
    current = root;
    queue.Clear();
  }

  /* ************************************************************************** */

  // BTBREADTHMUTABLEITERATOR

  // Specific constructors
  template <typename Data>
  BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data> &binary_tree) : BTBreadthIterator<Data>(binary_tree) {}

  // Copy constructor
  template <typename Data>
  BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator &iterator) : BTBreadthIterator<Data>(iterator) {}

  // Move constructor
  template <typename Data>
  BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator &&iterator) noexcept : BTBreadthIterator<Data>(std::move(iterator)) {}

  // Copy assignment
  template <typename Data>
  BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data> &iterator)
  {
    BTBreadthIterator<Data>::operator=(iterator);
    return *this;
  }

  // Move assignment
  template <typename Data>
  BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data> &&iterator) noexcept
  {
    BTBreadthIterator<Data>::operator=(std::move(iterator));
    return *this;
  }

  // Specific member functions (inherited from MutableIterator)

  // operator*()
  template <typename Data>
  Data& BTBreadthMutableIterator<Data>::operator*() 
  {
    if (current == nullptr)
    {
      throw std::out_of_range("BreadthMutableIterator is terminated");
    }
    else
    {
      return const_cast<Data &>(current->Element());
    }
  }

  /* ************************************************************************** */

}
