
namespace lasd {

/* ************************************************************************** */

// Specific constructors
template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& container) : Vector<Data>::Vector(container) {
    index = size;
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& container) : Vector<Data>::Vector(std::move(container)) {
    index = size;
}

// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec& stack) : Vector<Data>::Vector(stack) {
    index = stack.index;
}

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec&& stack) noexcept : Vector<Data>(std::move(stack)) {
    std::swap(index, stack.index);
}

// Destructor
template <typename Data>
StackVec<Data>::~StackVec() {
    delete[] Elements;
    Elements = nullptr;
}

// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stack) {
    Vector<Data>::operator=(stack);
    index = stack.index;
    return *this;
}

// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stack) noexcept {
    Vector<Data>::operator=(std::move(stack));
    std::swap(index, stack.index);
    return *this;
}

// Comparison operators
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stack) const noexcept {
    if(index == stack.index) {

        for(unsigned long i = 0; i < index; ++i) {
            if(Elements[i] != stack.Elements[i]){
                return false;
            }
        }
        return true;

    } else {
        return false;
    }
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stack) const noexcept {
    return !(*this == stack);
}

// Specific member functions (inherited from Stack)

// Top() (non-mutable)
template <typename Data>
const Data& StackVec<Data>::Top() const {
    if(index !=0) { 
        return Elements[index-1];
    } else {
        throw std::length_error("Stack is empty");
    }
}

// Top() (mutable)
template <typename Data>
Data& StackVec<Data>::Top() {
    if(index !=0) { 
        return Elements[index-1];
    } else {
        throw std::length_error("Stack is empty");
    }
}

// Pop()
template <typename Data>
void StackVec<Data>::Pop() {
    if(index != 0) {
        Reduce();
        --index;
    } else {
        throw std::length_error("Stack is empty");
    }
}


// TopNPop()
template <typename Data>
Data StackVec<Data>::TopNPop() {
    if(index != 0) {
        Reduce();
        return std::move(Elements[--index]);
    } else {
        throw std::length_error("Stack is empty");
    }
}

// Push (copy)
template <typename Data>
void StackVec<Data>::Push(const Data& data) {
    Expand();
    Elements[index++] = data;
}

// Push (move)
template <typename Data>
void StackVec<Data>::Push(Data&& data) {
    Expand();
    Elements[index++] = std::move(data);
}

// Specific member functions (inherited from Container)

// Empty()
template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return (index == 0);
}

// Size()
template <typename Data>
inline unsigned long StackVec<Data>::Size() const noexcept {
    return index;
}

// Specific member function (inherited from ClearableContainer)

// Clear
template <typename Data>
void StackVec<Data>::Clear() {
    index = 0;
    Vector<Data>::Resize(1);
}

// Auxiliary functions 

// Expand()
template <typename Data>
void StackVec<Data>::Expand() {
    if(index == size) {
        Vector<Data>::Resize(size * 2);
    }
}

// Reduce()
template <typename Data>
void StackVec<Data>::Reduce() {
    if(index == size / 4) {
        Vector<Data>::Resize(size / 2);
    }
}

/* ************************************************************************** */

}
