// Andrew Player
// CS311
// 10/26/2020
// Header for Project 5

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#ifndef __TFSARRAY_H_
#define __TFSARRAY_H_

template<typename T>
class TFSArray {
public:
    typedef T value_type;
    typedef size_t size_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;

public:

    TFSArray<value_type> ():
        _size(0), _arr(new value_type[0]), _capacity(0) {}
    TFSArray<value_type> (const size_type& size);
    TFSArray<value_type> (const TFSArray<value_type>& arr);
    TFSArray<value_type> (TFSArray<value_type>&& arr) noexcept;
   //~TFSArray<value_type>();

    TFSArray<value_type>& operator=(const TFSArray<value_type>& arr);
    TFSArray<value_type>& operator=(TFSArray<value_type>&& arr) noexcept;

    value_type& operator[](const size_type& location);
    const value_type& operator[](const size_type& location) const;

    size_type size() const;
    bool empty() const;
    void resize(const size_type& size);
    iterator insert(iterator it, const value_type& val);
    iterator erase(iterator it);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    void push_back(const value_type& val);
    void pop_back();
    void swap(TFSArray<value_type>& arr) noexcept;

private:
    void _swap(TFSArray<value_type>& arr);
    size_type _size;
    size_type _capacity;
    value_type* _arr;
};

template<typename value_type>
void TFSArray<value_type>::_swap(TFSArray<value_type>& arr) {
    std::swap(_size, arr._size);
    std::swap(_capacity, arr._capacity);
    std::swap(_arr, arr._arr);
    //for(int i = 0; i < arr._size; i++) {
    //   value_type temp = _arr[i];
    //   _arr[i] = arr._arr[i];
    //   arr._arr[i] = temp;
    //}
}

template<typename value_type>
TFSArray<value_type>::TFSArray(const size_type& size) {
    _size = size;
    _capacity = 2*size;
    _arr = new value_type[_capacity];
}

template<typename value_type>
TFSArray<value_type>::TFSArray(const TFSArray<value_type>& arr) {
    _size = arr._size;
    _capacity = arr._capacity;
    _arr = new value_type[_capacity];
    std::copy(arr.begin(), arr.end(), begin());
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
TFSArray<value_type>& TFSArray<value_type>::operator=(const TFSArray<value_type>& arr) {
    _size = arr._size;
    _capacity = arr._capacity;
    _arr = new value_type[_capacity];
    std::copy(arr.begin(), arr.end(), begin());
    return *this;
}

template<typename value_type>
TFSArray<value_type>& TFSArray<value_type>::operator=(TFSArray<value_type>&& arr) noexcept {
    _swap(arr);
    return *this;
}

template<typename value_type>
value_type& TFSArray<value_type>::operator[](const size_type& location) {
    return _arr[location];
}

template<typename value_type>
const value_type& TFSArray<value_type>::operator[](const size_type& location) const {
    return _arr[location];
}

template<typename value_type>
size_t TFSArray<value_type>::size() const {
    return _size;
}

template<typename value_type>
bool TFSArray<value_type>::empty() const {
    return _size == 0;
}

template<typename value_type>
void TFSArray<value_type>::resize(const size_type& size) {
    if(size >= _capacity) {
        TFSArray<value_type> temp(size);
        std::copy(begin(), end(), temp.begin());
        _swap(temp);
    } else {
        _size = size;
    }
}

template<typename value_type>
value_type* TFSArray<value_type>::insert(TFSArray<value_type>::iterator it, const value_type& val) {
    size_type location = it - begin();
    push_back(val);
    if(it == end()) {
        return end();
    }
    std::rotate(it, end()-1, end());
    return begin() + location;
}

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
value_type* TFSArray<value_type>::begin() {
    return &_arr[0];
}

template<typename value_type>
value_type* TFSArray<value_type>::end() {
    if(_size > 0) {
        return &_arr[_size];
    } else {
        return &_arr[0];
    }
}

template<typename value_type>
const value_type* TFSArray<value_type>::begin() const {
    return &_arr[0];
}

template<typename value_type>
const value_type* TFSArray<value_type>::end() const {
    if(_size > 0) {
        return &_arr[_size];
    } else {
        return &_arr[0];
    }
}

template<typename value_type>
void TFSArray<value_type>::push_back(const value_type& val) {
    resize(_size + 1);
    _arr[_size - 1] = val;
}

template<typename value_type>
void TFSArray<value_type>::pop_back() {
    _size--;
}

template<typename value_type>
void TFSArray<value_type>::swap(TFSArray<value_type>& arr) noexcept {
    _swap(arr);
}

#endif // __TFSARRAY_H_
