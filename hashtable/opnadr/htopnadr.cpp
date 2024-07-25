
namespace lasd {

  /* ************************************************************************** */

  // Default constructor
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr() : HashTable<Data>()
  {
    table_vector = Vector<Data>(table_size);

    for (unsigned long index = 0; index < table_size; index++)
    {
      flags_vector.operator[](index) = 'E'; // EMPTY
    }
  }

  // Specific constructors

  // A hash table of a given size
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size_value) : HashTable<Data>()
  {
    if ((size_value > 0) && (size_value != table_size))
    {
      table_size = HashTable<Data>::RoundTableSize(size_value);
      table_vector = Vector<Data>(table_size);
      Vector<char> temp_flags_vector = Vector<char>(table_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        temp_flags_vector.operator[](index) = 'E';
      }
      std::swap(flags_vector, temp_flags_vector);
    }
    else
    {
      // size di default
      table_vector = Vector<Data>(table_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        flags_vector.operator[](index) = 'E';
      }
    }
  }

  // A hash table obtained from a TraversableContainer
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &container) : HashTable<Data>()
  {
    table_vector = Vector<Data>(table_size);
    for (unsigned long index = 0; index < table_size; index++)
    {
      flags_vector.operator[](index) = 'E';
    }

    DictionaryContainer<Data>::InsertAll(container);
  }

  // A hash table of a given size obtained from a TraversableContainer
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size_value, const TraversableContainer<Data> &container) : HashTable<Data>()
  {
    if ((size_value > 0) && (size_value != table_size))
    {
      table_size = HashTable<Data>::RoundTableSize(size_value);
      table_vector = Vector<Data>(table_size);
      Vector<char> temp_flags_vector = Vector<char>(table_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        temp_flags_vector.operator[](index) = 'E';
      }
      std::swap(flags_vector, temp_flags_vector);

      DictionaryContainer<Data>::InsertAll(container);
    }
    else
    {
      // size di default
      table_vector = Vector<Data>(table_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        flags_vector.operator[](index) = 'E';
      }

      DictionaryContainer<Data>::InsertAll(container);
    }
  }

  // A hash table obtained from a MappableContainer
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&container) : HashTable<Data>() 
  {
    table_vector = Vector<Data>(table_size);
    for (unsigned long index = 0; index < table_size; index++)
    {
      flags_vector.operator[](index) = 'E';
    }

    DictionaryContainer<Data>::InsertAll(container);
  }

  // A hash table of a given size obtained from a MappableContainer
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long size_value, MappableContainer<Data> &&container) : HashTable<Data>()
  {
    if ((size_value > 0) && (size_value != table_size))
    {
      table_size = HashTable<Data>::RoundTableSize(size_value);
      table_vector = Vector<Data>(table_size);
      Vector<char> temp_flags_vector = Vector<char>(table_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        temp_flags_vector.operator[](index) = 'E';
      }
      std::swap(flags_vector, temp_flags_vector);

      DictionaryContainer<Data>::InsertAll(container);
    }
    else
    {
      // size di default
      table_vector = Vector<Data>(table_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        flags_vector.operator[](index) = 'E';
      }

      DictionaryContainer<Data>::InsertAll(container);
    }
  }

  // Copy constructor
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr &htable) : HashTable<Data>(htable)
  {
    table_vector = htable.table_vector;
    flags_vector = htable.flags_vector;
  }

  // Move constructor
  template <typename Data>
  HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr &&htable) noexcept : HashTable<Data>(std::move(htable))
  {
    std::swap(table_vector, htable.table_vector);
    std::swap(flags_vector, htable.flags_vector);
  }

  // Copy assignment
  template <typename Data>
  HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> &htable)
  {
    table_size = htable.table_size;
    size = htable.size;
    a = htable.a;
    b = htable.b;
    table_vector = htable.table_vector;
    flags_vector = htable.flags_vector;
    return *this;
  }

  // Move assignment
  template<typename Data>
  HashTableOpnAdr<Data> &HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> &&htable) noexcept {
    std::swap(table_size, htable.table_size);
    std::swap(size, htable.size);
    std::swap(a, htable.a);
    std::swap(b, htable.b);
    std::swap(table_vector, htable.table_vector);
    std::swap(flags_vector, htable.flags_vector);
    return *this;
  }

  // Comparison operators

  // Operator ==
  template <typename Data>
  bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &htable) const noexcept
  {

    if (size != htable.size)
    {
      return false;
    }
    else
    {
      for (unsigned long index = 0; index < table_size; index++)
      {
        if (flags_vector.operator[](index) == 'O')
        {
          if (!(htable.Exists(table_vector[index])))
          {
            return false;
          }
        }
      }
      return true;
    }
  }

  // Operator !=
  template <typename Data>
  bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr &htable) const noexcept
  {
    return !(*this == htable);
  }

  // Specific member functions (inherited from DictionaryContainer)

  // Insert() (Copy of the value)
  template <typename Data>
  bool HashTableOpnAdr<Data>::Insert(const Data &data)
  {
    Expand(); // effettua il check della table size ed eventualmente ridimensiona
    unsigned long index = FindEmpty(data); // ricerca indice disponibile per l'inserimento del dato

    if (flags_vector.operator[](index) == 'O') // dato gia' presente
    {
      return false; 
    }
    else
    {
      // inserimento del dato all'indice trovato
      flags_vector.operator[](index) = 'O'; // OCCUPED
      table_vector[index] = data;
      size++;
      return true;
    }
  }

  // Insert() (Move of the value)
  template <typename Data>
  bool HashTableOpnAdr<Data>::Insert(Data &&data)
  {
    Expand(); // effettua il check della table size ed eventualmente ridimensiona
    unsigned long index = FindEmpty(data); // ricerca indice disponibile per l'inserimento del dato

    if (flags_vector.operator[](index) == 'O') // dato gia' presente
    {
      return false;
    }
    else
    {
      // inserimento del dato all'indice trovato
      flags_vector.operator[](index) = 'O'; // OCCUPED
      table_vector[index] = std::move(data);
      size++;
      return true;
    }
  }

  // Remove()
  template <typename Data>
  bool HashTableOpnAdr<Data>::Remove(const Data &data)
  {
    // cerca l'indice del vettore che contiene il dato partendo dall'inizio
    unsigned long index = Find(data, 0); 

    if (index < table_size) 
    {
      // rimozione del dato trovato
      flags_vector.operator[](index) = 'D'; // DELETED
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
  bool HashTableOpnAdr<Data>::Exists(const Data &data) const noexcept
  {
    unsigned long index = Find(data, 0);

    if (index < table_size)
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
  void HashTableOpnAdr<Data>::Resize(const unsigned long new_size)
  {
    if (new_size == 0)
    {
      Clear();
    }
    else if (table_size != new_size)
    {
      HashTableOpnAdr<Data> *temp_htable = new HashTableOpnAdr(new_size);

      for (unsigned long index = 0; index < table_size; index++)
      {
        if (flags_vector.operator[](index) == 'O')
        {
          temp_htable->Insert(table_vector[index]);
        }
      }
      std::swap(*this, *temp_htable);
      delete temp_htable;
    }
  }

  // Specific member functions (inherited from ClearableContainer)

  // Clear()
  template <typename Data>
  void HashTableOpnAdr<Data>::Clear()
  {
    size = 0;
    table_size = 16;

    Vector<char> temp_flags_vector = Vector<char>(16);
    for (unsigned long index = 0; index < table_size; index++)
    {
      temp_flags_vector.operator[](index) = 'E'; // EMPTY
    }
    std::swap(flags_vector, temp_flags_vector);

    table_vector.Clear();
    table_vector.Resize(16);
  }

  // Auxiliary member functions

  // HashKey()
  template <typename Data>
  unsigned long HashTableOpnAdr<Data>::HashKey(Data data, unsigned long index) const
  {
    unsigned long base_hash = HashKey(data); // calcola hash di base del dato
    unsigned long probing_offset = (index * (index + 1)) / 2; // calcolo offset con funzione di probing quadratico
    return ((base_hash + probing_offset) % table_size); // calcolo dell'indice 
  }

  // Find()
  // cerca un dato all'interno della tabella usando il probing quadratico 
  template <typename Data>
  unsigned long HashTableOpnAdr<Data>::Find(Data data, unsigned long i) const
  {
    unsigned long index = HashKey(data, i); // calcolo dell'indice iniziale

    // itera finche' non raggiunge la fine della tabella o trova una cella non vuota
    while ((flags_vector.operator[](index) != 'E') && (i < table_size))
    {
      if ((table_vector[index] == data) && (flags_vector.operator[](index) == 'O'))
      {
        return index; // indice al dato trovato 
      }
      i++;
      index = HashKey(data, i);
    }

    // controllo finale
    if (flags_vector.operator[](index) == 'O')
    {
      if (table_vector[index] == data)
      {
        return index;
      }
    }

    return table_size; // index non trovato, restituisce table_size
  }

  // FindEmpty()
  // serve per trovare una posizione vuota all'interno della tabella oppure controlla se ci sia gia' il dato
  template <typename Data>
  unsigned long HashTableOpnAdr<Data>::FindEmpty(Data data) const
  {
    unsigned long i = 0;
    unsigned long index = HashKey(data, i); // indice iniziale

    // itera finche' non raggiunge la fine della tabella o trova una cella occupata
    while (flags_vector.operator[](index) == 'O' && i < table_size)
    {
      if (table_vector[index] == data)
      {
        return index; // il dato gia c'e'
      }
      i++;
      index = HashKey(data, i);
    }

    // controllo se l'indice e' marcato come cancellato
    if (flags_vector.operator[](index) == 'D')
    {
      unsigned long temp_index = Find(data, i);

      if (temp_index < table_size)
      {
        index = temp_index; // trovato
      }
    }

    return index; // restituisce l'ultimo indice controllato libero se il dato non c'e'
  }

  // Expand()
  template <typename Data>
  void HashTableOpnAdr<Data>::Expand()
  {
    if (size >= floor(table_size / 2)) // se la tabella e' piena per meta'
    {
      Resize(table_size + 1); // resize alla prossima potenza di due della table_size
    }
  }


  template <typename Data>
  void HashTableOpnAdr<Data>::PrintHT() const
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
