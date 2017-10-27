#include <iostream>

void siftdown(int i, int* buff ,int right) {
    while (2 * i + 1 <= right - 1) {
        int k = 2 * i + 1;
        if ((2 * i + 2 < right - 1) && (buff[2 * i + 2] < buff[2 * i + 1]))
            k = 2 * i + 2;
        if (buff[i] > buff[k]) {
            std::swap(buff[i], buff[k]);
            i = k;
        }
    }
}
void siftup(int i, int* buff) {
    while (buff[i] < buff[(i - 1) / 2]) {
        std::swap(buff[i], buff[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void build(int* arr, int* buff, int right) {
    for (int j = 0; j < right; ++j) {
        buff[j] = arr[j];
        siftup(j, buff);
    }
}

int main () {
    int elemNumber;
    std::cin >> elemNumber;
    int* arr = new int[elemNumber];
    int* buff = new int[elemNumber];
    for (int i = 0; i < elemNumber; ++i)
        std::cin >> arr[i];
    build(arr, buff, elemNumber);
    for (int i = 0; i < elemNumber; ++i)
        std::cout << buff[i] << " ";
    delete[] arr;
    delete[] buff;
    return 0;
}
