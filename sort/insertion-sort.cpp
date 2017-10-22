#include <iostream>

void insertionSort (int elemNumber, int* arr) {
    int j = 0, c = 0;
    for (int i = 1; i < elemNumber; ++i) {
        j = i - 1;
        c = arr[i];
        while ( (j >= 0) && (arr[j] > c) ) {
            arr[j+1] = arr[j];
            arr[j] = c;
            --j;
        }
    }
}

int main( ) {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    insertionSort(elemNumber, arr);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
