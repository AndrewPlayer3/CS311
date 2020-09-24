/*
 * Andrew Player
 * CS311
 * 09/24/2020
 * Header for Project 3 
*/

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <algorithm>

// Preconditions: Index should be > 0 and < size
// This function iteratively traverses the LL until it reaches 
// the index or it hits the end. Then it returns the data if possible. 
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    // Verify the LL is of size > 0 && has a positive index
    // If the LL is size 0, any integer for index is out of range. 
    if(index < 0 || head == nullptr) 
        throw std::out_of_range("Index below range in lookup function. LL size may be 0.");
       
    if(index == 0) return head->_data;

    std::size_t i = 0;
    LLNode<ValueType>* traveler = head->_next;

    // Travel through the LL until we reach our index or we hit the end    
    while(traveler != nullptr 
    && i < index - 1) {
        traveler = traveler->_next;
        i++;
    }

    if(traveler == nullptr) throw std::out_of_range("Index above range in lookup.");

    return traveler->_data;
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);

// Checks if the object is sorted in ascending order
// using the < comparison.
template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    // Empty should return true
    if(first == last) return true;
 
    FDIter prev = first;
    for(auto iter = ++first; iter != last; iter++) {
        // If the current value is less than the last, it isn't sorted.
        if(*iter < *prev) return false;
        prev++;
    }
    
    return true;
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED