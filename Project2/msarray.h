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
bool operator==(const MSArray<T>& a, const MSArray<T>& b) {
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++) {
        if(*(a.begin() + i) != *(b.begin() + i)) return false;
    }
    return true;
}

template <typename T>
bool operator!=(const MSArray<T>& a, const MSArray<T>& b) {
    return !(a == b);
}

template<typename T>
bool isEqual(const T& a, const T& b) {
    return !(a < b) && !(b < a);
}

template <typename T>
bool operator<(const MSArray<T>& a, const MSArray<T>& b) {
    
    // We only need to loop over the smallest number of elements
    int aSize = a.size();
    int bSize = b.size(); 
    int smallerSize = (aSize < bSize) ? aSize : bSize;
    
    for(int i = 0; i < smallerSize; i++) {
        
        T aVal = *(a.begin() + i);
        T bVal = *(b.begin() + i);

        if(isEqual(aVal, bVal)) continue;

        if(aVal <  bVal) return true;
        else return false;
    }

    // If we are here, the arrays are equivalent up to a[smallerSize]
    // so a is smaller iff a's size < b's size. 
    if(aSize < bSize) return true;
    return false;
}

template <typename T>
bool operator>(const MSArray<T>& a, const MSArray<T>& b) {
    if(!((a < b) || (isEqual(a, b)))) { // !(*this == array)
        return true;
    }
    return false;
}

template <typename T>
bool operator<=(const MSArray<T>& a, const MSArray<T>& b) {
    if(a < b || isEqual(a, b)) return true; 
    return false;
}

template <typename T>
bool operator>=(const MSArray<T>& a, const MSArray<T>& b) {
    if(a < b) return false; 
    return true;
}

#endif