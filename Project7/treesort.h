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
// Member Variables
private:
    value_type _data;
    std::unique_ptr<BSTree<value_type>> _left;
    std::unique_ptr<BSTree<value_type>> _right;>
    
// Member Types:
public:
    typedef value_type T

// Constructors and Destructors
public:
    BSTree() {
        _data  = 0;
        _left  = nullptr;
        _right = nullptr;
    }

// Member Functions
public:

};

template<typename FDIter>
void treesort(FDIter first, FDIter last);

#endif
