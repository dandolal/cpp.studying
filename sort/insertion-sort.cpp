#include <iostream>

void insertionSort (int elemNumber, int* arr) {
    int curNum = 0, curElem = 0;
    for (int i = 1; i < elemNumber; ++i) {
        curNum = i - 1;
        curElem = arr[i];
        while ( (curNum >= 0) && (arr[curNum] > curElem) ) {
            arr[curNum+1] = arr[curNum];
            arr[curNum] = curElem;
            --curNum;
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
