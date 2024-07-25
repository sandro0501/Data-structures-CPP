
#ifndef MYTEST_HPP
#define MYTEST_HPP

/* ************************************************************************** */

#include <iostream>
#include <string>
#include <random>
#include <stdexcept>
#include <string>
#include <limits>

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/traversable.hpp"
#include "../container/linear.hpp"
#include "../container/mappable.hpp"
#include "../container/dictionary.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

void mytest();

// test ex. 1

void myTestExercise1();
void testVectorUnsignedLongValues();
void testVectorDoubleValues();
void testVectorStringValues();
void testListUnsignedLongValues();
void testListDoubleValues();
void testListStringValues();
void testList();
void testStack();
void testQueue();

template <typename Stack>
void testStackUnsignedLongValues(Stack&, Stack&);
template <typename Stack>
void testStackDoubleValues(Stack&, Stack&);
template <typename Stack>
void testStackStringValues(Stack&, Stack&);

template <typename Queue>
void testQueueUnsignedLongValues(Queue&);
template <typename Queue>
void testQueueDoubleValues(Queue&);
template <typename Queue>
void testQueueStringValues(Queue&);

/* ************************************************************************** */
/* ************************************************************************** */

// test ex. 2

// costanti per la scelta della struttura dati
#define BTVEC 1
#define BTLNK 2
#define BSTT 3

// costanti per la scelta dell'iteratore
#define PREIT 1
#define INIT 2
#define POSTIT 3
#define BREADTHIT 4

// costanti per la scelta del tipo di dato
#define INT 1
#define DOUBLE 2
#define STRING 3

#define DIMENSIONE 10

void myTestExercise2();

unsigned int scegliStruttura();
unsigned int scegliTipoStruttura();

int generaInt();
double generaDouble();
std::string generaString();

template <typename Data>
void getValue(int &);
void getValue(double &);
void getValue(std::string &);
void getValue(unsigned int &);

void riempiLista(lasd::List<int> &);
void riempiLista(lasd::List<double> &);
void riempiLista(lasd::List<std::string> &);

template <typename Data>
void testBinaryTree(lasd::MutableBinaryTree<Data> &);
template <typename Data>
void testBST(lasd::BST<Data> &);

template <typename Data>
void testPreOrderIterator(lasd::BTPreOrderMutableIterator<Data> &);
template <typename Data>
void testPostOrderIterator(lasd::BTPostOrderMutableIterator<Data> &);
template <typename Data>
void testInOrderIterator(lasd::BTInOrderMutableIterator<Data> &);
template <typename Data>
void testBreadthIterator(lasd::BTBreadthMutableIterator<Data> &); 

template <typename Data>
void Increment(Data &data) {data += 1;} // MapFun

/* ************************************************************************** */
/* ************************************************************************** */

// test ex. 3

// costanti per la scelta della struttura dati
#define HTCLSADR 1
#define HTOPNADR 2

#define DIMENSIONE_HT 24

void myTestExercise3();

unsigned int scegliStrutturaHash();

void riempiHashTable(lasd::HashTable<int> &);
void riempiHashTable(lasd::HashTable<double> &);
void riempiHashTable(lasd::HashTable<std::string> &);

template <typename Data>
void testHashTable(lasd::HashTable<Data> &);

/* ************************************************************************** */

#endif
