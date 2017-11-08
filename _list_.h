#include <iostream>

template <typename T>
struct Node {
    T elem;
    Node* prev;
    Node* next;

    Node (T item) {
        Node* cur = new Node;
        cur->elem = item;
    }
};

template <typename T>
struct List {
    Node* first;
    Node* last;
    int size_;

    List() {
        first = last = nullptr;
        size_ = 0;
    }

    ~List() {
        for (int i = 0; i < size_; ++i)
            popBack();
        delete List;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    T& front() {
        return first->elem;
    }

    T& back() {
        return last->elem;
    }

    int size() const {
        return size_;
    }

    void pushBack(T newElem) {
        Node(newElem);
        cur->next = nullptr;
        if (size_ != 0) {
            last->next = cur;
            cur->prev = last;
            last = cur;
        } else {
            cur->prev = nullptr;
            last = first = cur;
        }
        ++size_;
    }

    void pushFront(T newElem) {
        Node(newElem);
        cur->prev = nullptr;
        if (size_ != 0) {
            first->prev = cur;
            cur->next = first;
            first = cur;
        } else {
            cur->next = nullptr;
            last = first = cur;
        }
        ++size_;
    }

    T popBack () {
        T curElem = last->elem;
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        return curElem;
        --size_;
    }

    T popFront () {
        T curElem = first->elem;
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        return curElem;
        --size_;
    }

    void reverse(Node* node = first) {
        if (node->next == nullptr) {
            std::swap(node->next, node->prev);
            return;
        }
        std::swap(node->next, node->prev);
        reverse(node->prev);
    }

    void insertBefore (Node* item, T value) {
        Node(value);
        cur->next = item;
        if (item == first) {
            first = cur;
            cur->prev = nullptr;
        } else {
            cur->prev = item->prev;
            item->prev->next = cur;
        }
        item->prev = cur;
        ++size_;
    }

    void insertAfter (Node* item, T value) {
        Node(value);
        cur->prev = item;
        if (item == last) {
            last = cur;
            cur->next = nullptr;
        } else {
            cur->next = item->next;
            item->next->prev = cur;
        }
        item->next = cur;
        ++size_;
    }

    void eraseBefore (Node* item) {
        if (item == first)
            return;
        Node* cur = item->prev;
        if (cur == first) {
            item->prev = nullptr;
            first = item;
        } else {
            item->prev = cur->prev;
            cur->prev->next = cur->next;
        }
        delete cur;
        --size_;
    }

    void eraseAfter (Node* item) {
        if (item == last)
            return;
        Node* cur = item->next;
        if (cur == last) {
            item->next = nullptr;
            last = item;
        } else {
            item->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        --size_;
    }

    void clear() {
        for (int i = 0; i < size_; ++i)
            popBack();
    }

    void swap(List li) {
        std::swap(first, li.first);
        std::swap(last, li.last);
    }
};

