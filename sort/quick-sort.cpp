#include <iostream>
int partArr(int* arr, int left, int right) {
    int pos = (right + left) / 2;
    int a = left, b = right - 1;
    while (a < pos) {
        if (arr[a] <= arr[pos])
            ++a;
        else {
            std::swap(arr[a], arr[pos]);
            std::swap(arr[a], arr[pos - 1]);
            --pos;
        }
    }
    while (b > pos) {
        if (arr[b] >= arr[pos])
            --b;
        else {
            std::swap(arr[b], arr[pos]);
            std::swap(arr[b], arr[pos + 1]);
            ++pos;
        }
    }
    return pos;
}

void quickSort(int* arr, int left, int right) {
    if (left == right - 1)
        return;
    partArr(arr, left, right);
    int pos = partArr(arr, left, right);
    quickSort(arr, left, pos);
    quickSort(arr, pos, right);

}


int main( ) {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    quickSort(arr, 0, elemNumber);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
