
namespace lasd {

/* ************************************************************************** */

// Specific member functions (Traversable Container)

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator acc) const {
    Traverse(
        [fun, &acc](const Data& dat) {
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& val) const noexcept {
    bool exists = false;
    Traverse(
        [val, &exists](const Data& dat) {
            exists |= (dat == val);
        }
    );
    return exists;
}

/* ************************************************************************** */

// Specific member functions (PreOrderTraversable Container)

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const {
    PreOrderTraverse(
        [fun, &acc](const Data& dat) {
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}

/* ************************************************************************** */

// Specific member functions (PostOrderTraversable Container)

template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const {
    PostOrderTraverse(
        [fun, &acc](const Data& dat) {
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void PostOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
    PostOrderTraverse(fun);
}

/* ************************************************************************** */

// Specific member functions (InOrderTraversable Container)

template <typename Data>
template <typename Accumulator>
inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> fun, Accumulator acc) const {
    InOrderTraverse(
        [fun, &acc](const Data& dat) {
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void InOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const {
    InOrderTraverse(fun);
}

/* ************************************************************************** */

// Specific member functions (BreadthOrderTraversable Container)

template <typename Data>
template <typename Accumulator>
inline Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> fun, Accumulator acc) const {
    BreadthOrderTraverse(
        [fun, &acc](const Data& dat) {
            acc = fun(dat, acc);
        }
    );
    return acc;
}

template <typename Data>
inline void BreadthTraversableContainer<Data>::Traverse(TraverseFun fun) const {
    BreadthTraverse(fun);
}

/* ************************************************************************** */

}