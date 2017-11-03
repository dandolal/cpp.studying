#include <iostream>

template <typename T>
class <vector> {
    
    T* buff_;
    T* copyBuff_;
    int size_, curElemNumber_;
  
  public:
      
    ~vector() {
        delete[] buff;
    }
    
    vector() {
        size_ = 1;
        curElemNumber_ = 0;
        buff_ = new T[size_];
        buff_ = new T[size_];
    }
    
    T front() const {
        return buff_[0];
    }
    
    T back() const {
        return buff_[curElemNumber_ - 1];
    }
    
    bool isEmpty() const {
        if (curElemNumber_ == 0) 
            return true;
        return false
    }
    
    void insert(int i, T elem) {
        if (size_ == curElemNumber_) {
            for (int j = 0; j < curElemNumber_; ++j)
                copyBuff_[j] = buff_[j];
            delete[] buff_;
            size_ = 2 * size_;
            ++curElemNumber_;
            buff_ = new T[size_];
            for (int j = 0; j < i; ++j)
                buff_[j] = copyBuff_[j];
            buff[i] = elem;
            for (int j = i; j < curElemNumber_ - 1)
                buff[j + 1] = copyBuff_[j];
            delete copyBuff_;
            copyBuff_ = new T [size_];
        } else{
            for (int j = curElemNumber_ - 1; j >= i; --j)
                buff_[j + 1] = buff_[j];
            buff_[i] = elem;
        }
    }
    
    void clear() {
        delete[] buff_;
        delete[] copyBuff_;
        curElemNumber_ = 0;
        buff_ = new T[size_];
        buff_ = new T[size_];
    }
    
    int capacity() const {
        return size_;
    }
    
    void erase(int i) {
        --curElemNumber_;
        for (int j = i; j < curElemNumber_; ++j) { 
            buff[j] = buff[j+1];
        }
        if (4*curElemNumber_ <= size_) {
            for (int j = 0; j < curElemNumber_; ++j) 
                copyBuff_[j] = buff[j];
            delete[] buff_;
            size_ = size_ / 2;
            buff_ = new T[size_];
            for (int j = 0; j < curElemNumber_; ++j)
                buff_[j] = copyBuff_[j];
            delete copyBuff_;
            copyBuff_ = new T [size_];
        }
    }
    
    void pushBack(T elem) {
        if (size_ == curElemNumber_) {
            for (int j = 0; j < curElemNumber_; ++j) 
                copyBuff_[j] = buff[j];
            delete[] buff_;
            size_ = size_ * 2;
            buff_ = new T[size_];
            for (int j = 0; j < curElemNumber_; ++j)
                buff_[j] = copyBuff_[j];
            delete copyBuff_;
            copyBuff_ = new T [size_];
        }
        buff_[curElemNumber_] = elem;
        ++curElemNumber_;
    }
    
    void popBack() {
        --curElemNumber_;
        if (4*curElemNumber_ <= size_) {
            for (int j = 0; j < curElemNumber_; ++j) 
                copyBuff_[j] = buff[j];
            delete[] buff_;
            size_ = size_ / 2;
            buff_ = new T[size_];
            for (int j = 0; j < curElemNumber_; ++j)
                buff_[j] = copyBuff_[j];
            delete copyBuff_;
            copyBuff_ = new T [size_];
        }
    }
    
    void resize(int count, T value) {
        if (curElemNumber_ + count > size_) {
            for (int j = 0; j < curElemNumber_; ++j) 
                copyBuff_[j] = buff[j];
            delete[] buff_;
            size_ = (curElemNumber_ + count) * 2;
            buff_ = new T[size_];
            for (int j = 0; j < curElemNumber_; ++j)
                buff_[j] = copyBuff_[j];
            delete copyBuff_;
            copyBuff_ = new T [size_];
        }
        for (int j = curElemNumber_; j < curElemNumber_ + count; ++j) 
            buff_[j] = value;
        curElemNumber_ = curElemNumber_ + count;
    }
    
    T at(int i) const {
        if (i !< curElemNumber_) 
            std::cout << "std::out_of_range" << std::endl;
        else
            return buff_[i];
    }
    
    void shrinkToFit() {
        for (int j = 0; j < curElemNumber_; ++j) 
            copyBuff_[j] = buff[j];
        delete[] buff_;
        size_ = curElemNumber_;
        buff_ = new T[size_];
        for (int j = 0; j < curElemNumber_; ++j)
            buff_[j] = copyBuff_[j];
        delete copyBuff_;
        copyBuff_ = new T [size_];
    }
};
