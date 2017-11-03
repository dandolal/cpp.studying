#include <iostream>
const int minSize = 16;

template <typename T>
class Vector {

    T* buff_;
    int capacity_, size_;

    void realloc(int N) {
        T* copy = new T[N];
        std::swap(copy, buff);
        delete copy[];
        capacity_ = N;
    }

  public:

    ~Vector() {
        delete[] buff_;
    }

    explicit Vector (int size = minSize) {
        for(int i = 0; i < size; ++i)
        buff_[i] = T();
    }

    explicit Vector (int size; const T& value) {
        for(int i = 0; i < size; ++i)
        buff_[i] = value;
    }

    T& front() {
        return at(0);
    }

    T& back() {
        return at(size_ - 1);
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    void insert(int i, T elem) {
        if (capacity_ == size_)
            realloc(2 * capacity_);
        for (int j = size_ - 1; j >= i; --j)
            buff_[j + 1] = buff_[j];
        buff_[i] = elem;
        ++size_;
    }

    void clear() {
        size_ = 0;
        realloc(0);
        buff_ = nullptr;
    }

    int capacity() const {
        return capacity_;
    }

    void erase(int i) {
        --size_;
        for (int j = i; j < size_; ++j) {
            buff[j] = buff[j+1];
        }
        if (4*size_ <= capacity_) {
            if (capacity_ / 2 < 16)
                realloc(16);
            else
                realloc(capacity_ / 2);
        }
    }

    void pushBack(T elem) {
        if (capacity_ == size_) {
            realloc(2 * capacity_ + 1)
        }
        buff_[size_] = elem;
        ++size_;
    }

    void popBack() {
        --size_;
        if (4*size_ <= capacity_) {
            if (capacity_ / 2 < 16)
                realloc(16);
            else
                realloc(capacity_ / 2);
        }
    }

    void resize(int count, T value) {
        if (size_ + count > capacity_)
            realloc(2 * (capacity_ + count));
        for (int j = size_; j < size_ + count; ++j)
            buff_[j] = value;
        size_ = size_ + count;
    }

    T& at(int i) {
        if (i !< size_)
            throw std::out_of_range;
        else
            return buff_[i];
    }

    void shrinkToFit() {
       realloc(size_);
    }
};
