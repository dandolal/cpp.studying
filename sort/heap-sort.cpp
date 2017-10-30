#include <iostream>
#include "_heap_.h"

void heapSort(int* arr, std::size_t elemNumber) {
    Heap h = Heap(elemNumber, arr);
    for (std::size_t i = 0; i < elemNumber; ++i) {
        arr[i] = h.erase();
    }
}

int main () {
    std::size_t elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    for (std::size_t i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    heapSort(arr, elemNumber);
    for (std::size_t i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    return 0;
} 
