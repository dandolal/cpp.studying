#include <iostream>
int partArr(int* arr, int* copyArr, int left, int right) {
    int pos = (right + left) / 2;
    int a = left, b = right - 1;
    int pivot = arr[pos];
    for (int i = left; i < right; ++i) {
        copyArr[i] = arr [i];
    }
    for (int i = left; i < right; ++i) {
        if (copyArr[i] < pivot) {
            arr[a] = copyArr[i];
            ++a;
        } else {
            arr[b] = copyArr[i];
            --b;
        }
    }
    return a;
}

void quickSort(int* arr, int* copyArr, int left, int right) {
    if (left == right - 1)
        return;
    partArr(arr, copyArr, left, right);
    int a = partArr(arr, copyArr, left, right);
    quickSort(arr, copyArr, left, a);
    quickSort(arr, copyArr, a, right);

}


int main( ) {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    int* copyArr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    quickSort(arr, copyArr, 0, elemNumber);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    delete[] copyArr;
    return 0;
}
