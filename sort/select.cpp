#include <iostream>

void insertionSort (int elemNumber, int* arr) {
    int curNum = 0, minElem = 0, numMinElem;
    for (int i = 0; i < elemNumber; ++i) {
        minElem = arr[i];
        numMinElem = i;
        for (curNum = i+1; curNum < elemNumber; ++curNum) {
            if (arr[curNum] < minElem) {
                minElem = arr[curNum];
                numMinElem = curNum;
            }
        }
        std::swap (arr[i], arr[numMinElem]);
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
