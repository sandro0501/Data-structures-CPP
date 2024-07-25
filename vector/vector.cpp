#include "vector.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific constructors (Vector)

template<typename Data>
Vector<Data>::Vector(const unsigned long new_size) {
    size = new_size;
    Elements = new Data[size]{}; // la notazione {} inizializza tutti gli elementi al valore di default
}

template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& container) {
    size = container.Size();
    Elements = new Data[size];
    unsigned long index = 0;
    container.Traverse(
        [this, &index](const Data& dat) {
            Elements[index++] = dat;
        }
    );
}

template<typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& container) {
    size = container.Size();
    Elements = new Data[size];
    unsigned long index = 0;
    container.Map(
        [this, &index](Data &dat){
            Elements[index++] = std::move(dat);
        }
    );
}

// Copy constructor
template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vector) {
    size = vector.size;
    Elements = new Data[size];
    std::copy(vector.Elements, vector.Elements + size, Elements);
}

// Move constructor
template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vector) noexcept {
    std::swap(size, vector.size);
    std::swap(Elements, vector.Elements);
}

//Destructor
template<typename Data>
Vector<Data>::~Vector() {
    delete[] Elements;
}

//Copy assignment
template <typename Data>
Vector<Data> &Vector<Data>::operator=(const Vector<Data>& vector) {
    Vector<Data> *temp_vector = new Vector<Data>(vector);
    std::swap(*temp_vector, *this);
    delete temp_vector;
    return *this;
} 

//Move assignment
template <typename Data>
Vector<Data> &Vector<Data>::operator=(Vector<Data>&& vector) noexcept {
    std::swap(size, vector.size);
    std::swap(Elements, vector.Elements);
    return *this;
}

//Operator ==
template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vector) const noexcept {
    bool flag = false;
    unsigned long i = 0;

    if (size != vector.size) {
        return flag;
    }
    else {
        for(i = 0; i<size; i++) {
            if(Elements[i] != vector.Elements[i]) {
                return flag;
            }
        }
        flag = true;
        return flag;
    }
}

//Operator !=
template <typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vector) const noexcept {
    return !(*this == vector);
}

//Specific member functions

//Clear
template <typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    Elements = nullptr;
    size = 0;
}

//Resize
template <typename Data>
void Vector<Data>::Resize(const unsigned long new_size) {
    unsigned long index = 0;
    unsigned long limit = 0;

    if(new_size == 0) {
        //se la nuova size e' uguale a 0, svuota il vector
        Clear(); 
    } 
    else if (size != new_size) {
        //dopo il confronto, assegna la dimensione più piccola alla variabile limit
        limit = (size < new_size) ? size : new_size; 
        Data* temp_vector = new Data[new_size] {}; 
        for(index = 0; index<limit; index++) {
            //copia degli elementi dal vettore corrente al nuovo
            temp_vector[index] = Elements[index];
        }
        std::swap(Elements, temp_vector);  //scambio puntatori
        size = new_size; //aggiornamento dimensione vector
        delete[] temp_vector; //eliminazione del vettore di appoggio usato per la copia 

    }
}

//Operator[] const
template <typename Data>
const Data& Vector<Data>::operator[](const unsigned long i) const {
    if (i<size) {
        return Elements[i];
    }
    else {
        throw std::out_of_range("Element of index: " + std::to_string(i) + "is out of range! Size is: " + std::to_string(size));
    }
}

//Operator[] 
template <typename Data>
Data& Vector<Data>::operator[](const unsigned long i) {
    if (i<size) {
        return Elements[i];
    }
    else {
        throw std::out_of_range("Element of index: " + std::to_string(i) + "is out of range! Size is: " + std::to_string(size));
    }
}

//Front const
template <typename Data>
const Data& Vector<Data>::Front() const {
    if(size!=0) {
        return Elements[0];
    } else {
        throw std::length_error("Vector is empty!");
    }
}

//Front
template <typename Data>
Data& Vector<Data>::Front() {
    if(size!=0) {
        return Elements[0];
    } else {
        throw std::length_error("Vector is empty!");
    }
}

//Back const
template <typename Data>
const Data& Vector<Data>::Back() const {
    if(size!=0) {
        return Elements[size-1];
    } else {
        throw std::length_error("Vector is empty!");
    }
}

//Back 
template <typename Data>
Data& Vector<Data>::Back() {
    if(size!=0) {
        return Elements[size-1];
    } else {
        throw std::length_error("Vector is empty!");
    }
}

/* ************************************************************************** */

//Sortable vector

//Specific constructors

template <typename Data>
SortableVector<Data>::SortableVector(const unsigned long new_size) : Vector<Data>(new_size) {}

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& container) : Vector<Data>(container) {}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& container) : Vector<Data>(std::move(container)) {}

//Copy constructor
template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector& vector) : Vector<Data>(vector) {}

//Move constructor
template <typename Data>
SortableVector<Data>::SortableVector(SortableVector&& vector) noexcept : Vector<Data>(std::move(vector)) {}

//Copy assigment
template <typename Data>
SortableVector<Data> &SortableVector<Data>::operator=(const SortableVector<Data>& vector) {
    Vector<Data>::operator=(vector);
    return *this;
}

//Move assignment
template <typename Data>
SortableVector<Data> &SortableVector<Data>::operator=(SortableVector<Data>&& vector) noexcept {
    Vector<Data>::operator=(std::move(vector));
    return *this;
}

/* ************************************************************************** */

}
