#include <iostream>

int main() {
    int* arr = new int(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    delete &arr[2];
}
