#include <iostream>
void mergeArr(int* arr, int* copyArr, int left, int right, int mid) {
    int a = left, b = mid;
    for (int i = left; i < right; ++i) {
        copyArr[i] = arr[i];
    }
    for (int i = left; i < right; ++i){
        if (a >= mid) {
            arr[i] = copyArr[b];
            ++b;
        } else if (b >= right) {
            arr[i] = copyArr[a];
            ++a;
        } else if (copyArr[a] < copyArr[b]) {
            arr[i] = copyArr[a];
            ++a;
        } else {
            arr[i] = copyArr[b];
            ++b;
        }
    }
}

void mergeSort(int* arr, int* copyArr, int left, int right) {
    if (left == right - 1)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, copyArr, left, mid);
    mergeSort(arr, copyArr, mid, right);
    mergeArr(arr, copyArr, left, right, mid);
}


int main( ) {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    int* copyArr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    mergeSort(arr, copyArr, 0, elemNumber);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    delete[] copyArr;
    return 0;
}
