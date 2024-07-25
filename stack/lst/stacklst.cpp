
namespace lasd {

/* ************************************************************************** */

// Specific constructors
template <typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data>& container) : List<Data>::List(container) {}

template <typename Data>
StackLst<Data>::StackLst(MappableContainer<Data>&& container) : List<Data>::List(std::move(container)) {}

// Copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stack) : List<Data>::List(stack) {}

// Move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stack) noexcept : List<Data>::List(std::move(stack)) {}

// Destructor
template <typename Data>
StackLst<Data>::~StackLst() {
    Clear();
    delete tail;
    delete head;
}

// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stack){
    List<Data>::operator=(stack);
    return *this;
}

// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stack) noexcept {
    List<Data>::operator=(std::move(stack));
    return *this;
}

// Comparison operators
template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept {
    return List<Data>::operator==(stack);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stack) const noexcept {
    return !(*this == stack);
}

// Specific member functions

// Top() (non-mutable)
template <typename Data>
const Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

// Top() (mutable)
template <typename Data>
Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

// Pop()
template <typename Data>
void StackLst<Data>::Pop() {
    List<Data>::RemoveFromFront();
}

// TopNPop()
template <typename Data>
Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

// Push() (copy)
template <typename Data>
void StackLst<Data>::Push(const Data& data) {
    List<Data>::InsertAtFront(data);
}

// Push() (move)
template <typename Data>
void StackLst<Data>::Push(Data&& data) noexcept {
    List<Data>::InsertAtFront(data);
}

/* ************************************************************************** */

}
