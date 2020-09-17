/*/
 *  Andrew Player
 *  CS311
 *  Project 2
 *  09/15/2020
/*/ 

#ifndef MSARRAY_H_
#define MSARRAY_H_

#include <iostream>
#include <typeinfo>

template<typename T>
class MSArray {

private:
    
    std::size_t _size;
    T* _data;

public:

    typedef T value_type;
    typedef std::size_t size_type;

    MSArray();
    MSArray(const MSArray<T>&  array);
    MSArray(      MSArray<T>&& array) noexcept;
    MSArray(const std::size_t& size );
    MSArray(const std::size_t& size, const T& fill);
   ~MSArray(); 

          T*    end  ();
          T*    begin();
    const T*    end  () const;
    const T*    begin() const;
    std::size_t size () const;

    MSArray<T>& operator=(const MSArray<T>&  array);
    MSArray<T>& operator=(MSArray<T>&& array) noexcept;

    T&   operator[](const std::size_t& location) const;
    
    bool operator< (const MSArray<T>& array) const;
    bool operator> (const MSArray<T>& array) const;
    bool operator<=(const MSArray<T>& array) const;
    bool operator>=(const MSArray<T>& array) const;
    bool operator==(const MSArray<T>& array) const;
    bool operator!=(const MSArray<T>& array) const;

};

template<typename T>
MSArray<T>::MSArray() {
    _size = 8;
    _data = new T[_size];
}

template<typename T>
MSArray<T>::MSArray(const MSArray<T>& array) {
    _size = array._size;
    _data = new T[_size];
    std::copy(array.begin(), array.end(), begin());
}

template<typename T>
MSArray<T>::MSArray(MSArray<T>&& array) noexcept{
    _size = array._size;
    _data = array._data;
    array._data = nullptr;
}

template<typename T>
MSArray<T>::MSArray(const std::size_t& size ) {
    _size = size;
    _data = new T[_size];
}

template<typename T>
MSArray<T>::MSArray(const std::size_t& size, const T& fill) {
    _size = size;
    _data = new T[_size];
    for(int i = 0; i < _size; i++) {
        _data[i] = fill;
    }
}

template<typename T>
MSArray<T>::~MSArray() {
    delete [] _data;
}

template<typename T>
T* MSArray<T>::end() {
    return &_data[_size];
}

template<typename T>
T* MSArray<T>::begin() {
    return &_data[0];
}

template<typename T>
const T* MSArray<T>::end() const {
    return &_data[_size];
}

template<typename T>
const T* MSArray<T>::begin() const {
    return &_data[0];
}

template<typename T>
std::size_t MSArray<T>::size() const {
    return _size;
}

template<typename T>
MSArray<T>& MSArray<T>::operator=(const MSArray<T>&  array){
    MSArray<T> temp(array);
    std::swap(_size, temp._size);
    std::swap(_data, temp._data);
    return *this;
}

template<typename T>
MSArray<T>& MSArray<T>::operator=(MSArray<T>&& array) noexcept{
    std::swap(_size, array._size);
    std::swap(_data, array._data);
    return *this;
}

template<typename T>
bool MSArray<T>::operator==(const MSArray<T>& array) const {
    if(_size != array._size) return false;
    for(int i = 0; i < _size; i++) {
        if(_data[i] != array._data[i]) return false;
    }
    return true;
}

template<typename T>
bool MSArray<T>::operator!=(const MSArray<T>& array) const {
    if(_size != array._size) return true;
    for(int i = 0; i < _size; i++) {
        if(_data[i] != array._data[i]) return true;
    }
    return false;
}

template<typename T>
T& MSArray<T>::operator[](const std::size_t& location) const {
    if(location >= 0 && location < _size) return _data[location];
    else std::cout << "ERROR HERE" << std::endl;
    return _data[0];
}


template<typename T>
bool MSArray<T>::operator< (const MSArray<T>& array) const {
    int smallerSize = (_size < array._size) ? _size : array._size;
    for(int i = 0; i < smallerSize; i++) {
        // If _data[i] == array._data[i] 
        if(!(_data[i] < array._data[i]) 
        && !(array._data[i] < _data[i])) continue;
        
        if(_data[i] <  array._data[i]) return true;
        else return false;
    }
    if(_size < array._size) return true;
    return false;
}


template<typename T>
bool MSArray<T>::operator>(const MSArray<T>& array) const {
    if(!(*this < array)
    && !(!(*this < array) && !(array < *this))) { // !(*this == array)
        return true;
    }
    return false;
}

template<typename T>
bool MSArray<T>::operator<=(const MSArray<T>& array) const {
    if(*this < array) return true; 
    
    // *this == array
    if(!(*this < array) && !(array < *this)) return true;
    return false;
}

template<typename T>
bool MSArray<T>::operator>=(const MSArray<T>& array) const {
    if(*this > array) return true;
    
    // *this == array
    if(!(*this < array) && !(array < *this)) return true;
    return false;
}

#endif