#include "list.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific constructors (Node)

template <typename Data>
List<Data>::Node::Node(const Data& data) {
    info = data;
}

template <typename Data>
List<Data>::Node::Node(Data&& data) noexcept {
    std::swap(info, data);
}

//Copy constructor (Node)
template <typename Data>
List<Data>::Node::Node(const Node& node) {
    if(node != nullptr) {
        info = node.info;
    }
}


//Move constructor (Node)
template <typename Data>
List<Data>::Node::Node(Node&& node) noexcept {
    if(node != nullptr) {
        std::swap(info, node.info);
        std::swap(next_node, node.next_node);
    }
}

//Comparison operators (Node)
template <typename Data>
bool List<Data>::Node::operator==(const Node& node) const noexcept { 
    bool flag = false;
    if ( (info == node.info) && ( (next_node == nullptr && node.next_node == nullptr) || 
    ((next_node != nullptr && node.next_node != nullptr) && (*next_node == *node.next_node)) ) ) {
        flag = true;
    }
    return flag;
}

template <typename Data>
bool List<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

//List

//Specific constructor 

template <typename Data>
List<Data>::List(const TraversableContainer<Data>& container) {
    container.Traverse(
        [this](const Data& info) {
            InsertAtBack(info);
        }

    );
}

template <typename Data>
List<Data>::List(MappableContainer<Data>&& container) {
    container.Map(
        [this](Data& info) {
            InsertAtBack(std::move(info));
        }
    );
}

//Copy constructor
template <typename Data>
List<Data>::List(const List<Data>& list) {
    if(list.size != 0){
        Node* temp = list.head;
        while(temp != nullptr){
            InsertAtBack(temp->info);
            temp = temp->next_node;
        }
    }
}

//Move constructor
template <typename Data>
List<Data>::List(List<Data>&& list) noexcept {
    std::swap(size, list.size);
    std::swap(head, list.head);
    std::swap(tail, list.tail);
}

//Destructor
template <typename Data>
List<Data>::~List() {
    while(head != nullptr) {
        Node* temp_node = head;
        head = head->next_node;
        delete temp_node;
    }
}

//Copy assignment
template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& copy_list) noexcept {
    Clear();
    if(copy_list.size != 0) {
        Node* temp_node = copy_list.head;
        while (temp_node != nullptr) {
            InsertAtBack(temp_node->info);
            temp_node = temp_node->next_node;
        }
    }
    return *this;
}

//Move assignment
template <typename Data>
List<Data>& List<Data>::operator=(List<Data>&& copy_list) noexcept {
    std::swap(size, copy_list.size);
    std::swap(head, copy_list.head);
    std::swap(tail, copy_list.tail);
    return *this;
}

//Comparison operators
template <typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept {
    if(size != list.size) {
        return false;
    }
    if(*(head) == *(list.head)) {
        return true;
    } else {
        return false; 
    }
}

template <typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept {
    return !(*this == list);
}

//Specific member functions

//Copy of the value
template <typename Data>
void List<Data>::InsertAtFront(const Data& info) {
    if(head == nullptr) {
        head = new Node(info);
        tail = head;
    } else {
        Node* new_node = new Node(info);
        new_node->next_node = head;
        head = new_node;
    }
    size++;
}

//Move of the value
template <typename Data>
void List<Data>::InsertAtFront(Data&& node_info) {
    if (head == nullptr) {
        Node* node = new Node();
        node->info = std::move(node_info);
        head = node;
        tail = head;
    } else {
        Node* node = new Node();
        node->info = std::move(node_info);
        node->next_node = head;
        head = node;
    }
    size++;
}

//RemoveFromFront
template <typename Data>
void List<Data>::RemoveFromFront(){
    if (size == 0) {
        throw std::length_error("Can't remove the node: the list is empty");
    } else {
        Node* temp_node = head;
        head = head->next_node;
        delete temp_node;
        size--;
    }
}

//FrontNRemove
template <typename Data>
Data List<Data>::FrontNRemove(){
    if (size == 0) {
        throw std::length_error("Can't remove the node: the list is empty");
    } else {
        Data front_info = Front();    
        RemoveFromFront();
        return front_info;
    }    
}

//InsertAtBack (copy)
template <typename Data>
void List<Data>::InsertAtBack(const Data& info){
    if (head == nullptr){
        Node* node = new Node(info);
        head = node;
        tail = node;
    }
    else {
        Node* node = new Node(info);
        tail->next_node = node;
        tail = node;
    }
    size++;
}

//InsertAtBack (move)
template<typename Data>
void List<Data>::InsertAtBack(Data&& new_info) {
    if (head == nullptr){
        Node* node = new Node;
        node->info = std::move(new_info);
        head = node;
        tail = head;
    }
    else{
        Node* node = new Node;
        node->info = std::move(new_info);
        tail->next_node = node;
        tail = node;
    }
    size++;
}

//Clear (inherited from ClearableContainer)
template <typename Data>
void List<Data>::Clear() noexcept {
    unsigned long limit = size;
    for(unsigned long i=0; i < limit; i++) {
        RemoveFromFront();
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Specific member functions (inherited from DictionaryContainer)

// Copy of the value
template <typename Data>
bool List<Data>::Insert(const Data& info) {
    if(TraversableContainer<Data>::Exists(info)) { //sfrutta la funzione Exists per verificare se il dato esiste già
        return false;
    } else {
        InsertAtBack(info);
        return true;
    }
}

// Move of the value
template<typename Data>
bool List<Data>::Insert(Data&& data) {
    Data info = std::move(data);
    if (TraversableContainer<Data>::Exists(info)) {
        return false;
    } else {
        InsertAtBack(std::move(info));
        return true;
    }
}

//Remove
template<typename Data>
bool List<Data>::Remove(const Data& info) {
    if (head == nullptr) {
        return false;
    } else if (head->info == info) {
        RemoveFromFront();
        return true;
    } else {

        Node* current = head;
        Node* next = head->next_node;

        while (next != nullptr) {
            if (next->info == info) {         
                current->next_node = next->next_node;
                delete next;
                next = nullptr;
                size--;

                if (current->next_node == nullptr){
                    tail = current;
                }
                return true;
            }
            current = next;
            next = next->next_node;
        }
        return false;
    }
}

// Specific member functions (inherited from LinearContainer)

// operator[] (NonMutable)
template <typename Data>
const Data& List<Data>::operator[](const unsigned long index) const {
    unsigned long limit = index;
    if (index >= size) {
        throw std::out_of_range("Index: "+std::to_string(index)+" is out of range. List size is: "+std::to_string(size));
    } else {
        Node* temp_node = head;
        while(temp_node != nullptr) {
            if (limit == 0) {
                return temp_node->info;
            } else {
                temp_node = temp_node->next_node;
                limit--;
            }
        }
        return temp_node->info;
    }    
}

// operator[] (Mutable)
template <typename Data>
Data& List<Data>::operator[](const unsigned long index) {
    unsigned long limit = index;
    if (index >= size) {
        throw std::out_of_range("Index: "+std::to_string(index)+" is out of range. List size is: "+std::to_string(size));
    } else {
        Node* temp_node = head;
        while(temp_node != nullptr) {
            if (limit == 0) {
                return temp_node->info;
            } else {
                temp_node = temp_node->next_node;
                limit--;
            }
        }
        return temp_node->info;
    }    
}

// Front() (NonMutable)
template <typename Data>
const Data& List<Data>::Front() const {
    if(size > 0) {
        return head->info;
    } else {
        throw std::length_error("List is empty");
    }
}

// Front() (Mutable)
template <typename Data>
Data& List<Data>::Front() {
    if(size > 0) {
        return head->info;
    } else {
        throw std::length_error("List is empty");
    }
}

// Back() (NonMutable)
template <typename Data>
const Data& List<Data>::Back() const {
    if(size > 0) {
        return tail->info;
    } else {
        throw std::length_error("List is empty");
    }
}

// Back() (Mutable)
template <typename Data>
Data& List<Data>::Back() {
    if(size > 0) {
        return tail->info;
    } else {
        throw std::length_error("List is empty");
    }
}

// Specific member function (inherited from TraversableContainer)

// Traverse
template <typename Data>
inline void List<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun, head);
}

// Specific member function (inherited from PreOrderTraversableContainer)

// PreOrderTraverse
template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun fun) const {
    PreOrderTraverse(fun, head);
}

// Specific member function (inherited from PostOrderTraversableContainer)

// PostOrderTraverse
template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverse(fun, head);
}

// Specific member function (inherited from MappableContainer)

// Map
template <typename Data>
inline void List<Data>::Map(MapFun fun) {
    PreOrderMap(fun, head);
}

// Specific member function (inherited from PreOrderMappableContainer)

// PreOrderMap
template <typename Data>
inline void List<Data>::PreOrderMap(MapFun fun) {
    PreOrderMap(fun, head);
}

// Specific member function (inherited from PostOrderMappableContainer)

// PostOrderMap
template <typename Data>
inline void List<Data>::PostOrderMap(MapFun fun) {
    PostOrderMap(fun, head);
}

// Auxiliary functions

//For TraversableContainer
template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const {
    for(; node != nullptr; node = node->next_node){
        fun(node->info);
    }
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const {
    if(node != nullptr){
        PostOrderTraverse(fun, node->next_node);
        fun(node->info);
    }
}

//For MappableContainer
template <typename Data>
void List<Data>::PreOrderMap(MapFun fun, Node* node){
    for(; node != nullptr; node = node->next_node){
        fun(node->info);
    }
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun fun, Node* node){
    if(node != nullptr){
        PostOrderMap(fun, node->next_node);
        fun(node->info);
    }
}

/* ************************************************************************** */

}
