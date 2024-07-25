
namespace lasd {

  #include <string>

/* ************************************************************************** */

  // Hashable

  // operator() int
  template <>
  class Hashable<int>
  {
    public:
      unsigned long operator()(const int &data) const noexcept
      {
        return (data * data);
      }
  };

  // operator() double
  template <>
  class Hashable<double>
  {
    public:
      unsigned long operator()(const double &data) const noexcept
      {
        long integer_part = floor(data);
        // calcola la parte frazionaria e la scala moltiplicandola per 2^24 per ottenere un valore intero
        long fractional_part = pow(2, 24) * (data - integer_part); 
        return (integer_part * fractional_part);
      }
  };

  // operator() string
  template <>
  class Hashable<std::string>
  {
    public:
      unsigned long operator()(const std::string &data) const noexcept
      {
        unsigned long prime = 31;
        unsigned long hash = 0;

        // per ogni carattere il suo valore ASCII viene moltiplicato
        // per la potenza del numero primo scelto il cui valore corrisponde alla posizione del carattere nella stringa
        // il risultato viene sommato all'hash corrente
        for (unsigned long i = 0; i < data.length(); i++)
        {
          hash = hash + data[i] * pow(prime, i);
        }

        return hash;
      }
  };

  // HashTable

  // Default constructor
  template <typename Data>
  HashTable<Data>::HashTable()
  {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<unsigned long> dist_a(0, prime - 1);
    std::uniform_int_distribution<unsigned long> dist_b(1, prime - 1); // termine costante

    a = dist_a(gen);
    b = dist_b(gen);

    //garantisce che a sia dispari per migliorare il processo di hashing 
    if (a % 2 == 0)
    {
      a++; 
    }

    size = 0;
  }

  // Copy constructor
  template <typename Data>
  HashTable<Data>::HashTable(const HashTable &htable)
  {
    a = htable.a;
    b = htable.b;
    table_size = htable.table_size;
    size = htable.size;
  }

  // Move constructor
  template <typename Data>
  HashTable<Data>::HashTable(HashTable &&htable) noexcept
  {
    std::swap(a, htable.a);
    std::swap(b, htable.b);
    std::swap(table_size, htable.table_size);
    std::swap(size, htable.size);
  }

  // Auxiliary member functions

  // HashKey
  template <typename Data>
  unsigned long HashTable<Data>::HashKey(const Data &data) const // calcola l'indice di hash
  {
    unsigned long x = hash_function.operator()(data); // calcola l'hash dell'oggetto data
    return (((a * x) + b) % prime) % table_size; // applica la funzione di hash universale
  }

  // RoundTableSize
  // per garantire che la dimensione della tabella hash sia una potenza di 2
  template <typename Data>
  unsigned long HashTable<Data>::RoundTableSize(unsigned long value)
  {
    // il controllo parte dalla potenza 2^4, quindi di default per value più piccoli la size impostata di default è 16 
    unsigned long exponent = 4; 

    while (pow(2, exponent) < value)
    {
      exponent++;
    }

    return pow(2, exponent); // sara' poi la nuova table_size
  }

/* ************************************************************************** */

}
