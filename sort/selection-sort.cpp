#include <iostream>

void insertionSort (int elemNumber, int* arr) {
    int curInd = 0, minElemInd;
    for (int i = 0; i < elemNumber; ++i) {
        minElemInd = i;
        for (curInd = i + 1; curInd < elemNumber; ++curInd) {
            if (arr[curInd] < arr[i]) {
                std::swap (arr[i], arr[curInd]);
                minElemInd = curInd;
            }
        }
    }
}

int main( ) {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    insertionSort (elemNumber, arr);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
