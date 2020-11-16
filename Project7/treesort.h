// Andrew Player
// CS311 - Project 7
// 11/16/2020
// Header for Project 7

#ifndef _TREESORT_H_
#define _TREESORT_H_

#include <iostream>
#include <memory>
#include <algorithm>

template<typename T>
class BSTree {
// Member Types:
public:
    typedef T value_type;

// Member Variables
private:
    value_type _data;
    std::unique_ptr<BSTree<value_type>> _left;
    std::unique_ptr<BSTree<value_type>> _right;
    
// Constructors and Destructors
public:
    // Default Constructor
    // Guarantee: Strong
    // Preconditions: None
    BSTree() {
        _data  = 0;
        _left  = nullptr;
        _right = nullptr;
    }

// Member Functions
public:
    // Insert data into the proper location in the tree
    // Guarantee: Strong
    // Preconditions: None
    std::unique_ptr<BSTree<value_type>> insert(
        std::unique_ptr<BSTree<value_type>> node,
        value_type data
    );

    // In-Order Traversal of the Binary Tree
    // Guarantee: Strong
    // Preconditions: None
    void traverse();

};

// Stable sort that sorts into the memory of the original tree
// Guarantee: Strong
// Preconditions: None
template<typename FDIter>
void treesort(FDIter first, FDIter last);

template<typename value_type>
std::unique_ptr<BSTree<value_type>> BSTree<value_type>::insert(
    std::unique_ptr<BSTree<value_type>> node,
    value_type data
) {
    return node;
}

void traverse() {
    return;
}

#endif
