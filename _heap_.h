#include <iostream>
const int buffSize = 1000000;

class Heap {

    int* buff;
    int size;

  public:

    ~Heap() {
        delete[] buff;
    }

    Heap(int elemnumber, int* arr) {
        size = elemnumber;
        int* buff = new int[buffSize];
        build(arr, size);
    }

    int getSize() const {
        return size;
    }

    void siftDown(int i) {
        while (2 * i + 1 <= size - 1) {
            int k = 2 * i + 1;
            if ((2 * i + 2 < size - 1) && (buff[2 * i + 2] < buff[2 * i + 1]))
                k = 2 * i + 2;
            if (buff[i] > buff[k]) {
                std::swap(buff[i], buff[k]);
                i = k;
            }
        }
    }

    void siftUp(int i) {
        while (buff[i] < buff[(i - 1) / 2]) {
            std::swap(buff[i], buff[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void build(int* arr, int size) {
        for (int j = 0; j < size; ++j) {
            buff[j] = arr[j];
            siftUp(j);
        }
    }

    int eraseMin() {
        int min = buff[0];
        buff[0] = buff[size - 1];
        --size;
        siftDown(0);
        return min;
    }

    void newElem(int newElem) {
        ++size;
        buff[size - 1];
        siftUp(size - 1);
    }

    int get_min() {
        return buff[0];
    }
};
