
namespace lasd {

/* ************************************************************************** */

// Specific constructors
template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& container) : Vector<Data>::Vector(container) {
    head = 0;
    tail = size;
    Vector<Data>::Resize(size * 2);
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& container) : Vector<Data>::Vector(std::move(container)) {
    head = 0;
    tail = size;
    Vector<Data>:: Resize(size * 2);
}

// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& queue) : Vector<Data>::Vector(queue) {
    head = queue.head;
    tail = queue.tail;
}

// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& queue) noexcept : Vector<Data>::Vector(std::move(queue)) {
    std::swap(head, queue.head);
    std::swap(tail, queue.tail);
}

// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec() {
    delete[] Elements;
    Elements = nullptr;
}

// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queue){
    Vector<Data>::operator=(queue);
    head = queue.head;
    tail = queue.tail;
    return *this;
}

// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queue) noexcept {
    Vector<Data>::operator=(std::move(queue));
    std::swap(head, queue.head);
    std::swap(tail, queue.tail);
    return *this;
}

// Comparison operators
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& queue) const noexcept {
    if(Size() == queue.Size()) {
        unsigned long i = head;
        unsigned long j = queue.head;
        for(unsigned long limit = 0; limit < Size(); limit++){
            if(Elements[i] != queue.Elements[j]){
                return false;
            }
            i=(i+1)%size;
            j=(j+1)%queue.size;
        }
        return true;
    } else {
        return false;
    }
}


template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& queue) const noexcept {
    return !(*this == queue);
}

// Specific member functions (inherited from Queue)

// Head() (non-mutable)
template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if(Empty()) {
        throw std::length_error("Queue is empty");
    } else {
        return Elements[head];
    }
}

// Head() (mutable)
template <typename Data>
Data& QueueVec<Data>::Head() {
    if(Empty()) {
        throw std::length_error("Queue is empty");
    } else {
        return Elements[head];
    }
}

// Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue(){
    if(Empty()) {
        throw std::length_error("Queue is empty");
    } else {
        head = (head+1) % size;
        if (Size() < (size/2) ) {
            Reduce();
        }
    }
}

// HeadNDequeue()
template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
     if(Empty()) {
        throw std::length_error("Queue is empty");
    } else {
        Data data = Elements[head];
        head = (head+1) % size;
        if (Size() < (size/2) ) {
            Reduce();
        }
        return data;
    }
}

// Enqueue (move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data) noexcept {
    if(Size() == size-1) {
        Expand();
    }
    Elements[tail] = std::move(data);
    tail = (tail+1)%size;
}

// Enqueue (copy)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data){
    if(Size() == size-1) {
        Expand();
    }
    Elements[tail] = data;
    tail = (tail+1)%size;
}

// Specific member functions (inherited from Container)

// Empty()
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    return (head == tail);
}

// Size()
template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    return ((size + tail - head) % size);
}

// Specific member function (inherited from ClearableContainer)

// Clear()
template <typename Data>
void QueueVec<Data>::Clear() noexcept {
    delete[] Elements;
    Elements = new Data[2];
    head = 0;
    tail = 0;
    size = 2;
}

// Auxiliary functions

// Expand()
template <typename Data>
void QueueVec<Data>::Expand() {
    Data* new_array = new Data[size*2] {};
    unsigned long temp_head = head;

    for(unsigned long i = 0; i<Size(); i++) {
       new_array[i] = Elements[temp_head];
       temp_head = (temp_head+1)%size;
    }
    tail = size-1;
    head = 0;
    std::swap(Elements, new_array);
    size = size*2; 
    delete[] new_array;
}

// Reduce()
template <typename Data>
void QueueVec<Data>::Reduce() {
    Data* new_array = new Data[size/2] {};
    unsigned long temp_head = head;

    for(unsigned long i = 0; i<Size(); i++) {
       new_array[i] = Elements[temp_head];
       temp_head = (temp_head+1)%size;
    }
    tail = Size();
    head = 0;
    std::swap(Elements, new_array);
    size = size/2;
    delete[] new_array;
}


/* ************************************************************************** */

}
