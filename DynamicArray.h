#ifndef LABA2_DYNAMICARRAY_H
#define LABA2_DYNAMICARRAY_H

#include "Functions.h"
#include <iostream>
#include <random>

static std::random_device rd;
using namespace std;

template<class T>
class DynamicArray {
private:
    T *head;
    int len = 0;
public:
    DynamicArray();

    DynamicArray(T *items, int size);

    explicit DynamicArray(int size);

    DynamicArray(const DynamicArray &obj);

    ~DynamicArray();

    int &operator[](int index);

    int getSize();

    T getElem(int index);

    T get(int index);

    void Set(int index, T value);

    void resize(int newSize);

    void print();

    void insertAt(T value, int index);

    void removeAt(int index);

    DynamicArray<T> getSubSeq(int start, int end);

    DynamicArray<T> concat(DynamicArray<T> seq1, DynamicArray<T> seq2);

    void reverse();

    void swap(int i, int j);

    void replace (T value, int index);
};

template<class T>
void DynamicArray<T>::replace(T value, int index) {
    if (index < len && index >= 0) {
        head[index] = value;
    } else {
        cout << "IndexOutOfRange" << endl;
    }
}

template<class T>
DynamicArray<T>::DynamicArray() {
    len = 0;
    head = (T *) malloc(sizeof(T));
    head[0] = 0;
}

template<class T>
DynamicArray<T>::DynamicArray(T *items, int size) {
    len = size;
    head = (T *) malloc(size * sizeof(T));
    for (int i = 0; i < size; ++i) {
        head[i] = items[i];
    }
}

template<class T>
DynamicArray<T>::DynamicArray(int size) {
    len = size;
    head = (T *) malloc(size * sizeof(T));
    cout << "Select how to fill in the array:" << endl;
    cout << "0 - All elements are filled in randomly" << endl;
    cout << "1 - To introduce elements" << endl;
    int a;
    cin >> a;
    if (a == 0) {
        for (int i = 0; i < size; ++i) {
            head[i] = rd() % 10;
        }
        return;
    }
    if (a == 1) {
        for (int i = 0; i < size; ++i) {
            cin >> head[i];
        }
        return;
    }
    for (int i = 0; i < size; ++i) {
        head[i] = 0;
    }
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray &obj) {
    len = obj.len;
    head = (T *) malloc(len * sizeof(T));
    for (int i = 0; i < len; ++i) {
        head[i] = obj.head[i];
    }
}

template<class T>
DynamicArray<T>::~DynamicArray() {
    free(head);
}

template<class T>
int &DynamicArray<T>::operator[](const int index) {
    return head[index];
}

template<class T>
int DynamicArray<T>::getSize() {
    return len;
}

template<class T>
T DynamicArray<T>::getElem(int index) {
    if (index < len && index >= 0) {
        return head[index];
    } else {
        cout << "IndexOutOfRange" << endl;
    }
}

template<class T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < len && index >= 0) {
        head[index] = value;
    } else {
        cout << "IndexOutOfRange" << endl;
    }
}

template<class T>
void DynamicArray<T>::resize(int newSize) {
    if (newSize <= 0) {
        cout << "IndexOutOfRange" << endl;
    } else {
        T *head2 = (T *) malloc(newSize * sizeof(T));
        if (newSize > len) {
            for (int i = 0; i < len; ++i) {
                head2[i] = head[i];
            }
            for (int i = len; i < newSize; ++i) {
                head2[i] = 0;
            }
        } else {
            for (int i = 0; i < newSize; ++i) {
                head2[i] = head[i];
            }
        }
        free(head);
        head = head2;
        len = newSize;
    }
}

template<class T>
void DynamicArray<T>::print() {
    for (int i = 0; i < len; ++i) {
        cout << head[i] << endl;
    }
}

template<class T>
void DynamicArray<T>::insertAt(T value, int index) {
    if (index < 0 || index > len) {
        cout << "IndexOutOfRange" << endl;
        return;
    }
    T *head2 = (T *) malloc((len + 1) * sizeof(T));
    int k = 0;
    for (int i = 0; i < len; ++i) {
        if (i == index) {
            k = 1;
        }
        head2[i + k] = head[i];
    }
    head2[index] = value;
    free(head);
    head = head2;
    ++len;
}

template<class T>
void DynamicArray<T>::removeAt(int index) {
    if (index < 0 || index > len) {
        cout << "IndexOutOfRange" << endl;
        return;
    }
    T *head2 = (T *) malloc((len - 1) * sizeof(T));
    int k = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i == index) {
            k = 1;
        }
        head2[i] = head[i + k];
    }
    free(head);
    head = head2;
    --len;
}

template<class T>
DynamicArray<T> DynamicArray<T>::getSubSeq(int start, int end) {
    if (start < 0 || start > len || end < 0 || end > len || end < start) {
        cout << "IndexOutOfRange" << endl;
        DynamicArray<T> a;
        return a;
    }
    T *head2 = (T *) malloc((end - start + 1) * sizeof(T));
    for (int i = 0; i < end - start + 1; ++i) {
        head2[i] = head[i + start];
    }
    DynamicArray<T> ab(head2, end - start + 1);
    free(head2);
    return ab;
}

template<class T>
DynamicArray<T> DynamicArray<T>::concat(DynamicArray<T> seq1, DynamicArray<T> seq2) {
    T *head2 = (T *) malloc((seq1.len + seq2.len) * sizeof(T));
    for (int i = 0; i < seq1.len; ++i) {
        head2[i] = seq1[i];
    }
    for (int i = 0; i < seq2.len; ++i) {
        head2[i + seq1.len] = seq2[i];
    }
    DynamicArray<T> ab(head2, seq1.len + seq2.len);
    free(head2);
    return ab;
}

template<class T>
void DynamicArray<T>::reverse() {
    T c;
    for (int i = 0; i <= (len) / 2; ++i) {
        c = head[i];
        head[i] = head[len - i - 1];
        head[len - i - 1] = c;
    }
}

template<class T>
T DynamicArray<T>::get(int index) {
    return head[index];
}

template<class T>
void DynamicArray<T>::swap(int i, int j) {
    int k = head[i];
    head[i] = head[j];
    head[j] = k;
}

#endif //LABA2_DYNAMICARRAY_H
