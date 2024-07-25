
namespace lasd {

/* ************************************************************************** */

// Comparison operators

template <typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& container) const noexcept {
    bool flag = true;
    unsigned long index = 0;

    if(size != container.size) {
        flag = false;
        return flag;
    }
    else {
        for (index = 0; index<size; index++) {
            if(operator[](index) != container[index]) {
                flag = false;
            }
        }
        return flag;
    }
}

template <typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& container) const noexcept {
    return !(*this == container);
}

/* ************************************************************************** */

// Specific member functions

template <typename Data>
const Data& LinearContainer<Data>::Front() const {
    return operator[](0);
}

template <typename Data>
Data& LinearContainer<Data>::Front() {
    return operator[](0);
}

template <typename Data>
const Data& LinearContainer<Data>::Back() const {
    return operator[](size - 1);
}

template <typename Data>
Data& LinearContainer<Data>::Back() {
    return operator[](size - 1);
}

/* ************************************************************************** */

// Specific member function (inherited from TraversableContainer)

template <typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}

// Specific member function (inherited from PreOrderTraversableContainer)

template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
    for(unsigned long index = 0; index < size; index++){
        fun(operator[](index));
    }
}

// Specific member function (inherited from PostOrderTraversableContainer)

template <typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
    unsigned long index = size;
    while (index > 0) {
        fun(operator[](--index));
    }
}

/* ************************************************************************ */

// Specific member function (inherited from MappableContainer)

template <typename Data>
inline void LinearContainer<Data>::Map(MapFun fun){
    PreOrderMap(fun);
}

// Specific member function (inherited from PreOrderMappableContainer)

template <typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun fun){
    for(unsigned long index = 0; index < size; ++index) {
        fun(operator[](index));
    }
}

// Specific member function (inherited from PostOrderMappableContainer)

template <typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun fun){
    unsigned long index = size;
    while(index > 0){
        fun(operator[](--index));
    }
}

/* ************************************************************************ */

// Comparison operators (Sortable Container)

template <typename Data>
bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer& container) const noexcept {
    bool flag = true;
    unsigned long index = 0;

    if(size != container.size) {
        flag = false;
        return flag;
    }
    else {
        for (index = 0; index<size; index++) {
            if(operator[](index) != container[index]) {
                flag = false;
            }
        }
        return flag;
    }
}

template <typename Data>
bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer& container) const noexcept {
    return !(*this == container);
}

/* ************************************************************************ */

// Specific member function (Sortable Container)

template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    QuickSort(0, size - 1);
}

template <typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long p, unsigned long r) noexcept {
    if (p < r) {
        unsigned long q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
    }
}

template <typename Data>
unsigned long SortableLinearContainer<Data>::Partition(unsigned long p, unsigned long r) noexcept {
    Data x = operator[](p);
    unsigned long i = p - 1;
    unsigned long j = r + 1;
    do {
        do { j--; } while (x < operator[](j));
        do { i++; } while (x > operator[](i));
        if (i < j) { std::swap(operator[](i), operator[](j)); }
    }
    while (i < j);
    return j;
}

/* ************************************************************************** */

}
