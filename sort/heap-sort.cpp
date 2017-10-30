#include <iostream>
#include "_heap_.h"


int main () {
    std::size_t elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    for (std::size_t i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    Heap h = Heap(elemNumber, arr);
    for (std::size_t i = 0; i < elemNumber; ++i) {
        arr[i] = h.erase();
        std::cout << arr[i] << " ";
    }
    delete[] arr;

    return 0;
}
