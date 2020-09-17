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

//Invariants: _size >= 0

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
    void        mswap(MSArray<T>& array);

    MSArray<T>& operator=(const MSArray<T>&  array);
    MSArray<T>& operator=(      MSArray<T>&& array) noexcept;

    T&   operator[](const std::size_t& location) const;
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
    array._size = 0;
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
void MSArray<T>::mswap(MSArray<T>& array) {
    std::swap(_size, array._size);
    std::swap(_data, array._data);
}

template<typename T>
MSArray<T>& MSArray<T>::operator=(const MSArray<T>&  array){
    MSArray<T> temp(array);
    mswap(temp);
    return *this;
}

template<typename T>
MSArray<T>& MSArray<T>::operator=(MSArray<T>&& array) noexcept{
    mswap(array);
    return *this;
}

// Precondition: location >= 0 (throw if location < 0)
template<typename T>
T& MSArray<T>::operator[](const std::size_t& location) const {
    if(location >= 0 && location < _size) return _data[location];
    else throw "Attempted to pass a negative array location";
}

template <typename T>
bool operator==(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1.size() != a2.size()) return false;
    for(int i = 0; i < a1.size(); i++) {
        if(*(a1.begin() + i) != *(a2.begin() + i)) return false;
    }
    return true;
}

template <typename T>
bool operator!=(const MSArray<T>& a1, const MSArray<T>& a2) {
    return !(a1 == a2);
}

template <typename T>
bool operator<(const MSArray<T>& a1, const MSArray<T>& a2) {
    
    // We only need to loop over the smallest number of elements
    int a1size = a1.size();
    int a2size = a2.size(); 
    int smallerSize = (a1size < a2size) ? a1size : a2size;
    
    for(int i = 0; i < smallerSize; i++) {
        
        // If _data[i] == array._data[i] skip this iteration
        if(!(*(a1.begin() + i) < *(a2.begin() + i)) 
        && !(*(a2.begin() + i) < *(a1.begin() + i))) continue;
        
        if(*(a1.begin() + i) <  *(a2.begin() + i)) return true;
        else return false;
    }

    // If we are here, the arrays are equivalent up to _data[smallerSize]
    // so the (this) is smaller iff _size < array._size. 
    if(a1size < a2size) return true;
    return false;
}

template <typename T>
bool operator>(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(!(a1 < a2)
    && !(!(a1 < a2) && !(a2 < a1))) { // !(*this == array)
        return true;
    }
    return false;
}

template <typename T>
bool operator<=(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1 < a2) return true; 
    
    // *this == array
    if(!(a1 < a2) && !(a2 < a1)) return true;
    return false;
}

template <typename T>
bool operator>=(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1 < a2) return false; 
    return true;
}

#endif