#include <iostream>
#include "tfsarray.h"

int main() {
    TFSArray<int> arr(5);
    for(int i = 0; i < 5; i++) {
        arr[i] = i;
        //std::cout << arr[i] << ", ";
    }
    //std::cout << std::endl;
    //std::cout << std::endl;
    int* result;
    int size = arr.size();
    //std::cout << arr.begin() << " " << arr.end() << std::endl;
    for(int i = 0; i < size + 1; i++) {
        result = arr.insert(arr.end(), i);
    }
    //std::cout << arr.begin() << " " << arr.end() << std::endl;
    //std::cout << arr.end() - arr.begin() << std::endl;
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;
    //std::cout << *result << " " << *arr.end() << std::endl;
    //std::cout << result << " " << arr.end() << std::endl;
    //std::cout << arr.end() - result << std::endl;

    const size_t SIZE = size_t(10);
    TFSArray<int> * tip = new TFSArray<int>(SIZE);
    for (size_t i = 0; i < SIZE; ++i)
    {
        (*tip)[i] = 15-int(i)*int(i);
    }

    // Make copy (copy assn)
    TFSArray<int> ticopy;
    ticopy = *tip;
    // Destroy original
    delete tip;

    std::cout << ticopy.size() << std::endl;

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << (ticopy[i] == 15-int(i)*int(i)) << std::endl;
    }

}
