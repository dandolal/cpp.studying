#include <iostream>
const int MIN_CAPACITY = 16;

template <typename T>
class Vector {

    T* buff_;
    int capacity_, size_;

    void realloc(int N) {
        T* copy = new T[N];
        for (int i =0; i < size_; ++i)
            copy[i] = buff_[i];
        delete[] buff_;
        buff_ = copy;
        capacity_ = N;
    }

  public:

    ~Vector() {
        delete[] buff_;
    }

    explicit Vector (int size = 0) {
        capacity_ = std::max(size, MIN_CAPACITY);
        buff_ = new T[capacity_];
        for (int i = 0; i < size; ++i)
            buff_[i] = T();
        size_ = size;
    }

    explicit Vector (int size, const T& value) {
        capacity_ = std::max(size, MIN_CAPACITY);
        buff_ = new T[capacity_];
        for (int i = 0; i < size; ++i)
            buff_[i] = value;
        size_ = size;
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

    int size () const {
        return size_;
    }

    void erase(int i) {
        if (isEmpty()) {
            throw std::out_of_range("EMPTY_VECTOR");
        --size_;
        for (int j = i; j < size_; ++j) {
            buff_[j] = buff_[j+1];
        }
        if (4*size_ <= capacity_) {
            if (capacity_ / 2 < MIN_CAPACITY)
                realloc(MIN_CAPACITY);
            else
                realloc(capacity_ / 2);
        }
    }

    void pushBack(T elem) {
        if (capacity_ == size_) {
            realloc(2 * capacity_ + 1);
        }
        buff_[size_] = elem;
        ++size_;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::out_of_range("EMPTY_VECTOR");
        T elem = buff_[size_ - 1];
        --size_;
        if (4*size_ <= capacity_) {
            if (capacity_ / 2 < MIN_CAPACITY)
                realloc(MIN_CAPACITY);
            else
                realloc(capacity_ / 2);
        }
        return elem;
    }

    void resize(int count, T value) {
        realloc(count);
        if (count > size_) {
            for (int i = size_; i < count; ++i)
                buff_[i] = value;
            size_ = count;
        }
    }

    T& at(int i) {
        if (i >= size_)
            throw std::out_of_range("OUT_OF_RANGE");
        return buff_[i];
    }

    void shrinkToFit() {
       realloc(size_);
    }
};
