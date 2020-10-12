#ifndef LABA2_ARRAYSEQUENCE_H
#define LABA2_ARRAYSEQUENCE_H

#include "DynamicArray.h"
#include "Sequence.h"

template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> *items;
public:
    void swap (int i, int j) override;

    int &operator[](const int index);

    DynamicArray<T> getItems() const;

    explicit ArraySequence(DynamicArray<T> arr);

    ArraySequence();

    ArraySequence(T *a, int size);

    explicit ArraySequence(int size);

    ArraySequence(const ArraySequence<T> &obj);

    ~ArraySequence() override;

    int getLen() override;

    T get(int i) override;

    void insertAt(T value, int index) override;

    void addNode(T value) override;

    void removeAt(int index) override;

    void print() override;

    ArraySequence<T> *getSub(int start, int end);

    ArraySequence<T> getSubSeq(int start, int end);

    ArraySequence<T> concat(ArraySequence<T> seq1, ArraySequence<T> seq2);

    void create(int size) override;

    void createRandom(int size) override;

    void reverse() override;

    void replace (T value, int index) override;
};

template<class T>
void ArraySequence<T>::replace(T value, int index) {
    this->items->replace(value, index);
}

template<class T>
void ArraySequence<T>::createRandom(int size) {
    for (int i = 0; i < size; ++i) {
        this->addNode(rand() % 100000);
    }
}

template<class T>
void ArraySequence<T>::create(int size) {
    for (int i = 0; i < size; ++i) {
        int a;
        cin >> a;
        this->addNode(a);
    }
}

template<class T>
void ArraySequence<T>::swap (int i, int j) {
    this->items->swap(i, j);
}


template<class T>
int &ArraySequence<T>::operator[](const int index) {
    return this->items->operator[](index);
}

template<class T>
DynamicArray<T> ArraySequence<T>::getItems() const {
    return *items;
}

template<class T>
ArraySequence<T>::ArraySequence(DynamicArray<T> arr) {
    this->items = new DynamicArray<T>(arr);
}

template<class T>
ArraySequence<T>::ArraySequence() {
    this->items = new DynamicArray<T>();
}

template<class T>
ArraySequence<T>::ArraySequence(T *a, int size) {
    this->items = new DynamicArray<T>(a, size);
}

template<class T>
ArraySequence<T>::ArraySequence(int size) {
    this->items = new DynamicArray<T>(size);
}

template<class T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &obj) {
    this->items = new DynamicArray<T>(obj.getItems());
}

template<class T>
ArraySequence<T>::~ArraySequence() {
    delete items;
}

template<class T>
int ArraySequence<T>::getLen() {
    return this->items->getSize();
}

template<class T>
T ArraySequence<T>::get(int i) {
    return this->items->operator[](i);
}

template<class T>
void ArraySequence<T>::insertAt(T value, int index) {
    this->items->insertAt(value, index);
}

template<class T>
void ArraySequence<T>::addNode(T value) {
    this->items->insertAt(value, this->items->getSize());
}

template<class T>
void ArraySequence<T>::removeAt(int index) {
    this->items->removeAt(index);
}

template<class T>
void ArraySequence<T>::print() {
    this->items->print();
}

template<class T>
ArraySequence<T> *ArraySequence<T>::getSub(int start, int end) {
    DynamicArray<T> arr = this->items->getSubSeq(start, end);
    ArraySequence<T> a(arr);
    auto b = &a;
    return b;
}

template<class T>
ArraySequence<T> ArraySequence<T>::getSubSeq(int start, int end) {
    DynamicArray<T> arr = this->items->getSubSeq(start, end);
    ArraySequence<T> a(arr);
    return a;
}

template<class T>
ArraySequence<T> ArraySequence<T>::concat(ArraySequence<T> seq1, ArraySequence<T> seq2) {
    DynamicArray<T> arr = this->items->concat(seq1.getItems(), seq2.getItems());
    ArraySequence<T> a(arr);
    return a;
}

template<class T>
void ArraySequence<T>::reverse() {
    this->items->reverse();
}

#endif //LABA2_ARRAYSEQUENCE_H
