#ifndef LABA2_LINKEDLIST_H
#define LABA2_LINKEDLIST_H

#include "Functions.h"
#include <iostream>

using namespace std;

template<class T>
class LinkedList {
private:
    int len;
    list<T> *head;

    void setLen(int i);

public:
    LinkedList();

    LinkedList(const T *items, int size);

    LinkedList(list<T> *lst, int size);

    explicit LinkedList(int size);

    LinkedList(const LinkedList &obj);

    ~LinkedList();

    void addNode(T d);

    int &operator[](int index);

    T get(int index);

    int getLen();

    LinkedList<T> GetSubList(int startIndex, int endIndex);

    void insert(T value, int index);

    void replace(T value, int index);

    void removeFirst();

    void removeAt(int index);

    LinkedList<T> concat(LinkedList<T> list1, LinkedList<T> list2);

    void print();

    void reverse();

    void swap(int i, int j);
};


template<class T>
LinkedList<T>::LinkedList() {
    len = 0;
    head = nullptr;
}

template<class T>
void LinkedList<T>::setLen(int i) {
    len = i;
}

template<class T>
LinkedList<T>::LinkedList(const T *items, int size) {
    len = size;
    head = nullptr;
    for (int i = 0; i < size; ++i) {
        auto *nd = new list<T>();
        nd->data = items[size - i - 1];
        nd->next = head;
        head = nd;
    }
}

template<class T>
LinkedList<T>::LinkedList(list<T> *lst, int size) {
    len = size;
    head = nullptr;
    for (
            int i = 0;
            i < size;
            ++i) {
        auto *nd = new list<T>();
        nd->
                next = head;
        head = nd;
    }
    list<T> *head2 = head;
    for (
            int i = 0;
            i < size;
            ++i) {
        head2->
                data = lst->data;
        head2 = head2->next;
        lst = lst->next;
    }
}

template<class T>
LinkedList<T>::LinkedList(int size) {
    len = size;
    head = nullptr;

    cout << "Select how to fill in the array:" << endl;
    cout << "0 - All elements are filled in randomly" << endl;
    cout << "1 - To introduce elements" << endl;
    int a;
    cin >> a;

    if (a == 0) {
        for (int i = 0; i < size; ++i) {
            auto *nd = new list<T>();
            nd->data = rand() % 10;
            nd->next = head;
            head = nd;
        }
        return;
    }

    if (a == 1) {
        for (int i = 0; i < size; ++i) {
            auto *nd = new list<T>();
            cin >> nd->data;
            nd->next = head;
            head = nd;
        }
        return;
    }

    for (int i = 0; i < size; ++i) {
        auto *nd = new list<T>();
        nd->data = 0;
        nd->next = head;
        head = nd;
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj) {
    len = obj.len;
    head = nullptr;
    auto *head2 = obj.head;
    T *arr = (T *) malloc(obj.len * (sizeof(T)));
    for (int i = 0; i < len; ++i) {
        arr[i] = head2->data;
        head2 = head2->next;
    }
    for (int i = 0; i < len; ++i) {
        auto *nd = new list<T>();
        nd->data = arr[len - i - 1];
        nd->next = head;
        head = nd;
    }
    free(arr);
}

template<class T>
LinkedList<T>::~LinkedList() {
    list<T> *head2;
    while (head != nullptr) {
        head2 = head->next;
        delete head;
        head = head2;
    }
}

template<class T>
void LinkedList<T>::addNode(T d) {
    if (len == 0) {
        ++len;
        auto *nd = new list<T>();
        nd->data = d;
        nd->next = head;
        head = nd;
    } else {
        ++len;
        auto *nd = new list<T>();
        nd->data = d;
        nd->next = nullptr;
        auto head2 = head;
        while (head2->next != nullptr) {
            head2 = head2->next;
        }
        head2->next = nd;
    }
}

template<class T>
int &LinkedList<T>::operator[](const int index) {
    int i = 0;
    list<T> *head2 = head;
    while (i != index) {
        head2 = head2->next;
        ++i;
    }
    return head2->data;
}

template<class T>
T LinkedList<T>::get(int index) {
    int i = 0;
    list<T> *head2 = head;
    if (index >= 0 && index < len) {
        while (i != index) {
            head2 = head2->next;
            ++i;
        }
    }
    return head2->data;
}

template<class T>
int LinkedList<T>::getLen() {
    return len;
}

template<class T>
LinkedList<T> LinkedList<T>::GetSubList(int startIndex, int endIndex) {
    if (startIndex < 0 || startIndex > len || endIndex < 0 || endIndex > len || endIndex < startIndex) {
        cout << "IndexOutOfRange" << endl;
        LinkedList<T> a;
        return a;
    }
    auto *head3 = head;
    int i = 0;
    while (i != startIndex) {
        head3 = head3->next;
        ++i;
    }
    LinkedList<T> ab(head3, endIndex - startIndex + 1);
    return ab;
}

template<class T>
void LinkedList<T>::insert(T value, int index) {
    if (index < 0 || index > len) {
        cout << "IndexOutOfRange" << endl;
        return;
    }
    ++len;
    list<T> *head2 = head;
    int i = 0;
    while (i != index) {
        head2 = head2->next;
        ++i;
    }
    auto *a = new list<T>();
    a->next = head2->next;
    a->data = value;
    head2->next = a;
}

template<class T>
void LinkedList<T>::replace(T value, int index) {
    list<T> *head2 = head;
    int i = 0;
    while (i != index) {
        head2 = head2->next;
        ++i;
    }
    head2->data = value;
}

template<class T>
void LinkedList<T>::removeFirst() {
    if (len == 0) {
        cout << "IndexOutOfRange" << endl;
        return;
    }
    auto head2 = head;
    head = head->next;
    delete head2;
    --len;
}

template<class T>
void LinkedList<T>::removeAt(int index) {
    if (index < 1 || index > len) {
        if (index == 0) {
            removeFirst();
            return;
        }
        cout << "IndexOutOfRange" << endl;
        return;
    }
    --len;
    list<T> *head2 = head;
    int i = 0;
    while (i != index - 1) {
        head2 = head2->next;
        ++i;
    }
    auto head3 = head2->next;
    head2->next = head2->next->next;
    delete head3;
}

template<class T>
LinkedList<T> LinkedList<T>::concat(LinkedList<T> list1, LinkedList<T> list2) {
    list<T> *head1 = list1.head;
    list<T> *head2 = list2.head;
    T *arr = (T *) malloc((list1.len + list2.len) * sizeof(T));
    int i = 0;
    while (head1 != nullptr) {
        arr[i] = head1->data;
        head1 = head1->next;
        ++i;
    }
    while (head2 != nullptr) {
        arr[i] = head2->data;
        head2 = head2->next;
        ++i;
    }
    LinkedList<T> a(arr, list1.len + list2.len);
    free(arr);
    cout << "len " << list1.len + list2.len << endl;
    return a;
}

template<class T>
void LinkedList<T>::print() {
    list<T> *head2 = head;
    for (int i = 0; i < len; ++i) {
        cout << head2->data << endl;
        head2 = head2->next;
    }
}

template<class T>
void LinkedList<T>::reverse() {
    auto pre = head;
    auto cur = head;
    auto nx = head;

    pre = nullptr;
    nx = nx->next;
    while (nx != nullptr) {
        cur->next = pre;
        pre = cur;
        cur = nx;
        nx = cur->next;
    }
    cur->next = pre;
    head = cur;
}

template<class T>
void LinkedList<T>::swap(int i, int j) {
    int k = get(i);
    replace(get(j), i);
    replace(k, j);
}

#endif //LABA2_LINKEDLIST_H
