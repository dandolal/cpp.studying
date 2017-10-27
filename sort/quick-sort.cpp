#include <iostream>

int partArr(int* arr, int left, int right) {
    int b = right;
    int a = left;
    int pivot = arr[(left + right) / 2];
    while (a <= b) {
        while (arr[a] < pivot) 
            ++a;
        while (arr[b] > pivot) 
            --b;
        if (a <= b) 
            std::swap(arr[a++], arr[b--]);
    }
    return a;
}

void quickSort(int* arr, int left, int right) {
    if (left == right)
        return;
    partArr(arr, left, right);
    int a = partArr(arr, left, right);
    quickSort(arr, left, a - 1);
    quickSort(arr, a, right);

}


int main( ) {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    quickSort(arr, 0, elemNumber - 1);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
