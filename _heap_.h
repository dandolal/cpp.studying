#include <iostream>
const std::size_t buffSize = 1000000;

class Heap {
  
    int* buff_;
    std::size_t size_;
     
     void siftDown(std::size_t i) {
        while (2 * i + 1 < size_) {
            std::size_t k = 2 * i + 1;
            if ((2 * i + 2 < size_) && (buff_[2 * i + 2] < buff_[2 * i + 1]))
                k = 2 * i + 2;
            if (buff_[i] > buff_[k]) {
                std::swap(buff_[i], buff_[k]);
                i = k;
            }
            else
                break;
        }
    }

    void siftUp(std::size_t i) {
        while (buff_[i] < buff_[(i - 1) / 2]) {
            std::swap(buff_[i], buff_[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void build(int* arr, std::size_t size_) {
        for (std::size_t j = 0; j < size_; ++j) {
            buff_[j] = arr[j];
            siftUp(j);
        }
    }
  public:

    ~Heap() {
        delete[] buff_;
    }

    Heap(std::size_t elemnumber, int* arr) {
        size_ = elemnumber;
        buff_ = new int[buffSize];
        build(arr, size_);
    }

    std::size_t size() const {
        return size_;
    }

    int erase() {
        int min = buff_[0];
        buff_[0] = buff_[size_ - 1];
        --size_;
        siftDown(0);
        return min;
    }

    void add(int newElem) {
        ++size_;
        buff_[size_ - 1] = newElem;
        siftUp(size_ - 1);
    }

    int get () const {
        return buff_[0];
    }
};
