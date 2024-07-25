
namespace lasd {

/* ************************************************************************** */

// Specific constructors
template<typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data>& container) : List<Data>::List(container) {}

template<typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data>&& container) noexcept : List<Data>::List(std::move(container)){}

// Copy constructor
template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& queue) : List<Data>::List(queue) {}

// Move constructor
template<typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& queue) noexcept : List<Data>::List(std::move(queue)) {}

// Copy assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& queue) {
    List<Data>::operator=(queue);
    return *this;
}

// Move assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& queue) noexcept {
    List<Data>::operator=(std::move(queue));
    return *this;
}

// Comparison operators
template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& queue) const noexcept {
   return (List<Data>::operator==(queue));
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& queue) const noexcept {
   return !(*this == queue);
}

// Specific member functions (inherited from Queue)

// Head() (non-mutable version)
template<typename Data>
const Data& QueueLst<Data>::Head() const {
    return List<Data>::Front();
}

// Head() (mutable version)
template<typename Data>
Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

// Dequeue
template<typename Data>
void QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();
}

// HeadNDequeue
template<typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    return List<Data>::FrontNRemove();
}

// Enqueue (copy)
template<typename Data>
void QueueLst<Data>::Enqueue(const Data& data) {
    List<Data>::InsertAtBack(data);
}

// Enqueue (move)
template<typename Data>
void QueueLst<Data>::Enqueue(Data&& data) noexcept {
    List<Data>::InsertAtBack(std::move(data));
}

/* ************************************************************************** */

}
