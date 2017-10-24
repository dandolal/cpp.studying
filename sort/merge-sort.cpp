#include <iostream>
void mergeArr (int* arr, int* copyArr, int left, int right, int mid) {
    mid = (left+right)/2;
    int a = left, b = mid, i = 0;
    for (i = left; i < right; ++i) {
        copyArr[i] = arr[i];
    }
    for (i = left; i < right; ++i){
        if (a >= mid) {
            arr[i] = copyArr[b];
            ++b;
        } else if (b >= right) {
            arr[i] = copyArr[a];
            ++a;
        } else if (copyArr[a] < copyArr[b]) {
            arr[i] = copyArr [a];
            ++a;
        } else {
            arr[i] = copyArr [b];
            ++b;
        }
    }
    delete[] copyArr;
}

void mergeSort (int* arr, int* copyArr, int left, int right) {
    if (left == right)
        return;
    int mid = (left + right)/2;
    mergeSort (arr, copyArr, left, mid);
    mergeSort (arr, copyArr, mid + 1, right);
    mergeArr (arr, copyArr, left, right, mid);
}


int main( ) {
    int elemNumber;
    int left = 0;
    std::cin >> elemNumber;
    int right = elemNumber;
    int* arr = new int[elemNumber];
    int* copyArr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    mergeSort (arr, copyArr, 0, elemNumber);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    delete[] copyArr;
    return 0;
}
