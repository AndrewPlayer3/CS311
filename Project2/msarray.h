/*/
 *  Andrew Player
 *  CS311
 *  Project 2
 *  09/15/2020
/*/ 

#ifndef MSARRAY_H_
#define MSARRAY_H_

#include <iostream>

template<typename T>
class MSArray {

private:
    
    T _data[];

public:

    typedef T value_type;
    typedef std::size_t size_type;

    MSArray<T>();
    MSArray<T>(const MSArray<T>&     array);
    MSArray<T>(const MSArray<T>&&    array);
    MSArray<T>(const std::size_t& size );
    MSArray<T>(const std::size_t& size, const T& fill);

    T* end();
    T* begin();
    std::size_t size();

    MSArray<T>& operator=(const MSArray<T>&  array);
    MSArray<T>& operator=(const MSArray<T>&& array);

    T&   operator[](const std::size_t& locatior);
    
    bool operator< (const MSArray<T>& array);
    bool operator> (const MSArray<T>& array);
    bool operator<=(const MSArray<T>& array);
    bool operator>=(const MSArray<T>& array);
    bool operator==(const MSArray<T>& array);
    bool operator!=(const MSArray<T>& array);

};

#endif