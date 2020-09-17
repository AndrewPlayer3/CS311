#include "msarray.h"

template<typename T>
bool operator==(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1._size != a2._size) return false;
    for(int i = 0; i < a1._size; i++) {
        if(a1._data[i] != a2._data[i]) return false;
    }
    return true;
}

template<typename T>
bool operator!=(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1._size != a2._size) return true;
    for(int i = 0; i < a1._size; i++) {
        if(a1._data[i] != a2._data[i]) return true;
    }
    return false;
}

// I could have just used std::lexigraphical_order(begin(), end(), array.begin(), array.end())
// but I wanted to do it myself.
template<typename T>
bool operator<(const MSArray<T> a1, const MSArray<T>& a2) {
    
    // We only need to loop over the smallest number of elements 
    int smallerSize = (a1._size < a2._size) ? a1._size : a2._size;
    
    for(int i = 0; i < smallerSize; i++) {
        
        // If _data[i] == array._data[i] skip this iteration
        if(!(a1._data[i] < a2._data[i]) 
        && !(a2._data[i] < a1._data[i])) continue;
        
        if(a1._data[i] <  a2._data[i]) return true;
        else return false;
    }

    // If we are here, the arrays are equivalent up to _data[smallerSize]
    // so the (this) is smaller iff _size < array._size. 
    if(a1._size < a2._size) return true;
    return false;
}

template<typename T>
bool operator>(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(!(a1 < a2)
    && !(!(a1 < a2) && !(a2 < a1))) { // !(*this == array)
        return true;
    }
    return false;
}

template<typename T>
bool operator<=(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1 < a2) return true; 
    
    // *this == array
    if(!(a1 < a2) && !(a2 < a1)) return true;
    return false;
}

template<typename T>
bool operator>=(const MSArray<T>& a1, const MSArray<T>& a2) {
    if(a1 > a2) return true;
    
    // *this == array
    if(!(a1 < a2) && !(a2 < a1)) return true;
    return false;
}