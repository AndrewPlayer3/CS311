// Andrew Player
// CS311
// 10/26/2020
// Header for Project 5

#include <cstddef>
#include <stdexcept>
#include <algorithm>

#ifndef __TFSARRAY_H_
#define __TFSARRAY_H_

// Invariants:
// 0 <= _size <= _capacity
template<typename T>
class TFSArray {

// Member Type Declarations:
public:
    typedef T value_type;
    typedef size_t size_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;

// Member Variable Declarations:
private:
    size_type _size;
    size_type _capacity;
    value_type* _arr;

// Constructorsm, Destructor, and Assignments
public:


    // Default Constructor
    // Strong Guarantee
    TFSArray<value_type> ():
        _size(0), _arr(new value_type[0]), _capacity(0) {}

    // Size Constructor
    // Strong Guarantee
    TFSArray<value_type> (const size_type& size);

    // Copy Constructor
    // Strong Guarantee
    TFSArray<value_type> (const TFSArray<value_type>& arr);

    // Move Constructor
    // No-Throw Guarantee
    TFSArray<value_type> (TFSArray<value_type>&& arr) noexcept;

    // Destructor
    // No-Throw Guarantee
    ~TFSArray<value_type>();

    // Copy Assignment
    // Strong Guarantee
    TFSArray<value_type>& operator=(const TFSArray<value_type>& arr);

    // Move Assignment
    // No-Throw Guarantee
    TFSArray<value_type>& operator=(TFSArray<value_type>&& arr) noexcept;

// Member Functions and Overloads
public:

    // [] Overloads
    // Pre:
    //     0 <= location <= _size - 1
    // No-Throw Guarantee
    value_type& operator[](const size_type& location) noexcept;
    const value_type& operator[](const size_type& location) const noexcept;

    // Size Getter
    // No-Throw Guarantee
    size_type size() const noexcept;

    // Returns _size == 0
    // No-Throw Guarantee
    bool empty() const noexcept;

    // Resize the array to size
    // Pre:
    //     0 <= size
    // Strong Guarantee
    void resize(const size_type& size);

    // Insert val just before it
    // Pre:
    //     begin() <= it <= end()
    // Strong Guarantee
    iterator insert(iterator it, const value_type& val);

    // Erase the value at it
    // Pre:
    //     begin() <= it <= end()
    // Strong Guarantee
    iterator erase(iterator it);

    // Begin and End Iterators
    // No-Throw Guarantee
    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    // Insert val at the end of the array
    // Strong Guarantee
    void push_back(const value_type& val);

    // Remove the last elemet of the array
    // Strong Guarantee
    void pop_back();

    // Swap this and arr
    // No-Throw Guarantee
    void swap(TFSArray<value_type>& arr) noexcept;

};

template<typename value_type>
TFSArray<value_type>::TFSArray(const size_type& size) {
    _size = size;
    _capacity = 2*size;
    _arr = new value_type[_capacity];
}


template<typename value_type>
TFSArray<value_type>::TFSArray(const TFSArray<value_type>& arr) {    
    try {
        _size = arr._size;
        _capacity = arr._capacity;
        _arr = new value_type[_capacity];
        std::copy(arr.begin(), arr.end(), begin());
    } catch(std::runtime_error& e) {
        delete [] _arr;
        throw e;
    } catch(...) {
        delete [] _arr;
    } 
}

template<typename value_type>
TFSArray<value_type>::TFSArray(TFSArray<value_type>&& arr) noexcept {
    _capacity = arr._capacity;
    _size = arr._size;
    _arr = arr._arr;
    arr._size = 0;
    arr._capacity = 0;
    arr._arr = nullptr;
}

template<typename value_type>
TFSArray<value_type>::~TFSArray() {
    _size = 0;
    _capacity = 0;
    delete [] _arr;
}

template<typename value_type>
void TFSArray<value_type>::swap(TFSArray<value_type>& arr) noexcept {
    std::swap(_size, arr._size);
    std::swap(_capacity, arr._capacity);
    std::swap(_arr, arr._arr);
}

template<typename value_type>
TFSArray<value_type>& TFSArray<value_type>::operator=(const TFSArray<value_type>& arr) {
    TFSArray<value_type> temp(arr);
    swap(temp);
    return *this;
}

template<typename value_type>
TFSArray<value_type>& TFSArray<value_type>::operator=(TFSArray<value_type>&& arr) noexcept {
    swap(arr);
    return *this;
}

template<typename value_type>
value_type& TFSArray<value_type>::operator[](const size_type& location) noexcept {
    return _arr[location];
}

template<typename value_type>
const value_type& TFSArray<value_type>::operator[](const size_type& location) const noexcept {
    return _arr[location];
}

template<typename value_type>
size_t TFSArray<value_type>::size() const noexcept {
    return _size;
}

template<typename value_type>
bool TFSArray<value_type>::empty() const noexcept {
    return _size == 0;
}

// Resizes array to length size if _size < _capacity
// or 2 * size if size >= _capacity
template<typename value_type>
void TFSArray<value_type>::resize(const size_type& size) {
    if(size >= _capacity) {
        TFSArray<value_type> temp(size);
        std::copy(begin(), end(), temp.begin());
        swap(temp);
        return;
    }
    _size = size;
}

// Inserts val just before it
template<typename value_type>
value_type* TFSArray<value_type>::insert(TFSArray<value_type>::iterator it, const value_type& val) {
    size_type location = it - begin();

    push_back(val);

    if(it == end()) {
        return end();
    }

    std::rotate(begin() + location, end()-1, end());
    return begin() + location;
}

// Removes the value at it
template<typename value_type>
value_type* TFSArray<value_type>::erase(iterator it) {
    if(it == end()) {
        _size--;
        return end();
    }

    size_type next_location = it - begin();
    iterator next = it + 1;

    while(it < end()) {
        *it = *next;
        it++;
        next++;
    }

    _size--;
    return begin() + next_location;
}

template<typename value_type>
value_type* TFSArray<value_type>::begin() noexcept {
    return &_arr[0];
}

template<typename value_type>
value_type* TFSArray<value_type>::end() noexcept {
    return &_arr[_size];
}

template<typename value_type>
const value_type* TFSArray<value_type>::begin() const noexcept {
    return &_arr[0];
}

template<typename value_type>
const value_type* TFSArray<value_type>::end() const noexcept {
    return &_arr[_size];
}

// Inserts val at the end of the array
template<typename value_type>
void TFSArray<value_type>::push_back(const value_type& val) {
    resize(_size + 1);
    _arr[_size - 1] = val;
}

// Removes the last element of the array
template<typename value_type>
void TFSArray<value_type>::pop_back() {
    if(_size > 0) {
        _arr[_size - 1] = 0;
        _size--;
    }
}

#endif // __TFSARRAY_H_
