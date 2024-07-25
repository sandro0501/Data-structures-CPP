#include "htclsadr.hpp"

namespace lasd {

/* ************************************************************************** */

  // Default constructor
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr() : HashTable<Data>()
  {
    table_vector = Vector<BST<Data>>(table_size);
  }

  // Specific constructors

  // A hash table of a given size
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(unsigned long size_value) : HashTable<Data>()
  {
    if (size_value > 0)
    {
      table_size = HashTable<Data>::RoundTableSize(size_value);
    }
    table_vector = Vector<BST<Data>>(table_size);
  }

  // A hash table obtained from a TraversableContainer
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> &container) : HashTable<Data>()
  {
    table_vector = Vector<BST<Data>>(table_size);
    DictionaryContainer<Data>::InsertAll(container);
  }

  // A hash table of a given size obtained from a TraversableContainer
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(unsigned long size_value, const TraversableContainer<Data> &container) : HashTable<Data>()
  {
    if ((size_value > 0) && (size_value != table_size))
    {
      table_size = HashTable<Data>::RoundTableSize(size_value);
    }
    table_vector = Vector<BST<Data>>(table_size);
    DictionaryContainer<Data>::InsertAll(container);
  }

  // A hash table obtained from a MappableContainer
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> &&container) : HashTable<Data>()
  {
    table_vector = Vector<BST<Data>>(table_size);
    DictionaryContainer<Data>::InsertAll(container);
  }

  // A hash table of a given size obtained from a MappableContainer
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(unsigned long size_value, MappableContainer<Data> &&container) : HashTable<Data>()
  {
    if ((size_value > 0) && (size_value != table_size))
    {
      table_size = HashTable<Data>::RoundTableSize(size_value);
    }
    table_vector = Vector<BST<Data>>(table_size);
    DictionaryContainer<Data>::InsertAll(container);
  }

  // Copy constructor
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr &htable) : HashTable<Data>(htable)
  {
    table_vector = htable.table_vector;
  }

  // Move constructor
  template <typename Data>
  HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr &&htable) noexcept : HashTable<Data>(std::move(htable))
  {
    std::swap(table_vector, htable.table_vector);
  }

  // Copy assignment
  template <typename Data>
  HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> &htable)
  {
    table_size = htable.table_size;
    size = htable.size;
    a = htable.a;
    b = htable.b;
    table_vector = htable.table_vector;
    return *this;
  }

  // Move assignment
  template <typename Data>
  HashTableClsAdr<Data> &HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&htable) noexcept
  {
    std::swap(table_size, htable.table_size);
    std::swap(size, htable.size);
    std::swap(a, htable.a);
    std::swap(b, htable.b);
    std::swap(table_vector, htable.table_vector);
    return *this;
  }

  // Comparison operators

  // Operator ==
  template <typename Data>
  bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr &htable) const noexcept
  {
    if (size != htable.size)
    {
      return false;
    }
    else
    {
      bool flag = true;
      for (unsigned long index = 0; index < table_size; index++)
      {
        table_vector[index].Traverse(
          [this, &flag, &htable](const Data &data)
          { 
            flag &= htable.Exists(data); 
          }
        );
      }
      return flag;
    }
  }

  // Operator !=
  template <typename Data>
  bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr &table) const noexcept
  {
    return !(*this == table);
  }

  // Specific member functions (inherited from DictionaryContainer)

  // Insert() (Copy of the value)
  template <typename Data>
  bool HashTableClsAdr<Data>::Insert(const Data &data)
  {
    unsigned long index = HashKey(data);

    if ((table_vector[index]).Insert(data))
    {
      size++;
      return true;
    }
    else
    {
      return false;
    }
  }

  // Insert() (Move of the value)
  template <typename Data>
  bool HashTableClsAdr<Data>::Insert(Data &&data)
  {
    unsigned long index = HashKey(data);

    if ((table_vector[index]).Insert(std::move(data)))
    {
      size++;
      return true;
    }
    else
    {
      return false;
    }
  }

  // Remove()
  template <typename Data>
  bool HashTableClsAdr<Data>::Remove(const Data &data)
  {
    unsigned long index = HashKey(data);

    if ((table_vector[index]).Remove(data))
    {
      size--;
      return true;
    }
    else
    {
      return false;
    }
  }


  // Specific member functions (inherited from TestableContainer)

  // Exists()
  template <typename Data>
  bool HashTableClsAdr<Data>::Exists(const Data &data) const noexcept
  {
    unsigned long index = HashKey(data);

    if ((table_vector[index]).Exists(data))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // Specific member functions (inherited from ResizableContainer)

  // Resize()
  template <typename Data>
  void HashTableClsAdr<Data>::Resize(const unsigned long new_size)
  {
    if (new_size == 0)
    {
      Clear();
    }
    else if (table_size != new_size)
    {
      //se new size è maggiore di 0 approssima la nuova table size
      //con RoundTableSize chiamando il relativo costruttore (new_size di default e' 16)
      HashTableClsAdr<Data> *temp_htable = new HashTableClsAdr(new_size); 

      for (unsigned long index = 0; index < table_size; index++)
      {
        temp_htable->InsertAll(table_vector[index]);
      }

      std::swap(*this, *temp_htable);
      delete temp_htable;
    }
  }

  // Specific member functions (inherited from ClearableContainer)

  // Clear()
  template <typename Data>
  void HashTableClsAdr<Data>::Clear()
  {
    size = 0;
    table_vector.Clear();
    table_vector.Resize(16);
    table_size = 16;
  }

  template <typename Data>
  void HashTableClsAdr<Data>::PrintHT() const
  {
    if (table_vector.Empty())
    {
      std::cout << "Empty";
    }
    else
    {
      //for (unsigned long index = 0; index < table_size; ++index)
      //{
        std::cout << "Bucket " << index << ": ";
        //table_vector[index].Traverse([](const Data &data){ std::cout << data << "\n"; });
        table_vector.Traverse([](const Data &data){ std::cout << data << "\n"; });
      //}
    }
  }

/* ************************************************************************** */

}
