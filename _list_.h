#include <iostream>

template <typename T>
struct Node {
    T elem;
    Node* prev;
    Node* next;
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
        Node* cur = first;
        while (cur->next != nullptr)
            deleteElem(cur);
        delete cur;
        delete List;
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    Node* front() {
        return first;
    }

    Node* back() {
        return last;
    }

    int size() const {
        return size_;
    }

    void pushBack(T newElem) {
        Node* cur = new Node;
        cur->next = nullptr;
        cur->elem = newElem;
        if (first != nullptr) {
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
        Node* cur = new Node;
        cur->prev = nullptr;
        cur->elem = newElem;
        if (first != nullptr) {
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
        if (node->next == nullptr)
            return;
        std::swap(node->next, node->prev);
        reverse(node->prev);
    }

    void insertBefore (Node* item, T value) {
        Node* cur = new Node;
        cur->elem = value;
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
        Node* cur = new Node;
        cur->elem = value;
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
        Node* cur = first;
        while (cur->next != nullptr)
            deleteElem(cur);
        delete cur;
        size_ = 0;
        first = last = nullptr;
    }

    void swap(List li) {
        Node* cur1 = li1.first, li2.cur2 = li2.first;
        while (cur1->next != nullptr)
            swapElem(cur1, li2.cur2);
        std::swap(cur1, li2.cur2);
    }

   private:

    void deleteElem(Node* elem) {
        cur = elem->next;
        delete elem;
        deleteElem(cur);
    }

    void swapElem(Node* elem1, Node* li2.elem2) {
        cur1 = li1.elem1->next;
        li2.cur2 = li2.elem2->next;
        std::swap(elem1, li2.elem2);
        swapElem(cur1, li2.cur2);
    }
};

