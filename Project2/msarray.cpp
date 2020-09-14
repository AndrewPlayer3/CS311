/*/
 *  Andrew Player
 *  CS311
 *  Project 2
 *  09/15/2020
/*/ 

#include "msarray.h"

template<typename T>
MSArray<T>::MSArray() {
    _size = 8;
    for(int i = 0; i < _size; i++) {
        _data[i] = 0;
    }
}

template<typename T>
MSArray<T>::MSArray(const MSArray<T>& array) {
    _size = array._size;
    _data = array._data;
}

template<typename T>
MSArray<T>::MSArray(const MSArray<T>&& array) {
    _size = array._size;
    _data = array._data;
}

template<typename T>
MSArray<T>::MSArray(const std::size_t& size ) {
    _size = size;
    for(int i = 0; i < size; i++) {
        _data[i] = 0;
    }
}

template<typename T>
MSArray<T>::MSArray(const std::size_t& size, const T& fill) {
    _size = size;
    for(int i = 0; i < size; i++) {
        _data[i] = fill;
    }
}

template<typename T>
T* MSArray<T>::end() {
    return _data[_size - 1];
}

template<typename T>
T* MSArray<T>::begin() {
    return _data[0];
}

template<typename T>
std::size_t MSArray<T>::size() {
    return _size;
}

template<typename T>
MSArray<T>& MSArray<T>::operator=(const MSArray<T>&  array) {
    _size = array._size;
    _data = array._data;
}

template<typename T>
MSArray<T>& MSArray<T>::operator=(const MSArray<T>&& array) {
    _size = array._size;
    _data = array._data;
}

template<typename T>
T& MSArray<T>::operator[](const std::size_t& location) {
    if(location > 0 && location < _size) return _data[location];
    else std::cout << "ERROR HERE" << std::endl;
}

template<typename T>
bool MSArray<T>::operator< (const MSArray<T>& array) {

}

template<typename T>
bool MSArray<T>::operator>(const MSArray<T>& array) {

}

template<typename T>
bool MSArray<T>::operator<=(const MSArray<T>& array) {

}

template<typename T>
bool MSArray<T>::operator>=(const MSArray<T>& array) {

}

template<typename T>
bool MSArray<T>::operator==(const MSArray<T>& array) {

}

template<typename T>
bool MSArray<T>::operator!=(const MSArray<T>& array) {

}
