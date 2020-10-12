#ifndef LABA2_LINKEDLISTSEQUENCE_H
#define LABA2_LINKEDLISTSEQUENCE_H

#include "Functions.h"
#include "LinkedList.h"
#include "Sequence.h"

template<class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> *items;
public:
    void swap (int i, int j) override;

    int &operator[](const int index);

    LinkedList<T> *getItems() const;

    explicit LinkedListSequence(LinkedList<T> arr);

    LinkedListSequence();

    explicit LinkedListSequence(int size);

    LinkedListSequence(T *arr, int size);

    LinkedListSequence(const LinkedListSequence<T> &obj);

    ~LinkedListSequence() override;

    int getLen() override;

    T get(int i) override;

    void addNode(const T value) override;

    void insertAt(T value, int index) override;

    void removeAt(int index) override;

    void print() override;

    LinkedListSequence<T> *getSub(int start, int end);

    LinkedListSequence<T> getSubSeq(int start, int end);

    LinkedListSequence<T> concat(LinkedListSequence<T> seq1, LinkedListSequence<T> seq2);

    void reverse() override;

    void create(int size) override;

    void createRandom(int size) override;

    void replace(T value, int index) override;
};

template<class T>
void LinkedListSequence<T>::replace(T value, int index) {
    this->items->replace(value, index);
}

template<class T>
void LinkedListSequence<T>::createRandom(int size) {
    for (int i = 0; i < size; ++i) {
        this->addNode(rand() % 100000);
    }
}

template<class T>
void LinkedListSequence<T>::create(int size) {
    for (int i = 0; i < size; ++i) {
        T a;
        cin >> a;
        this->addNode(a);
    }
}
template<class T>
void LinkedListSequence<T>::swap (int i, int j) {
    this->items->swap(i, j);
}

template<class T>
int &LinkedListSequence<T>::operator[](const int index) {
    return this->items->operator[](index);
}

template<class T>
LinkedList<T> *LinkedListSequence<T>::getItems() const {
    return items;
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(LinkedList<T> arr) {
    this->items = new LinkedList<T>(arr);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence() {
    this->items = new LinkedList<T>();
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(int size) {
    this->items = new LinkedList<T>(size);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(T *arr, int size) {
    this->items = new LinkedList<T>(arr, size);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedListSequence<T> &obj) {
    this->items = new LinkedList<T>(obj.getItems());
}

template<class T>
LinkedListSequence<T>::~LinkedListSequence() {
    delete items;
}

template<class T>
int LinkedListSequence<T>::getLen() {
    return this->items->getLen();
}

template<class T>
T LinkedListSequence<T>::get(int i) {
    return this->items->operator[](i);
}

template<class T>
void LinkedListSequence<T>::addNode(const T value) {
    this->items->addNode(value);
}

template<class T>
void LinkedListSequence<T>::insertAt(T value, int index) {
    this->items->insert(value, index);
}

template<class T>
void LinkedListSequence<T>::removeAt(int index) {
    this->items->removeAt(index);
}

template<class T>
void LinkedListSequence<T>::print() {
    this->items->print();
}

template<class T>
LinkedListSequence<T> *LinkedListSequence<T>::getSub(int start, int end) {
    LinkedList<T> arr = this->items->GetSubList(start, end);
    LinkedListSequence<T> a(arr);
    LinkedListSequence<T> *b = &a;
    return b;
}

template<class T>
LinkedListSequence<T> LinkedListSequence<T>::getSubSeq(int start, int end) {
    LinkedList<T> arr = this->items->GetSubList(start, end);
    LinkedListSequence<T> a(arr);
    return a;
}

template<class T>
LinkedListSequence<T> LinkedListSequence<T>::concat(LinkedListSequence<T> seq1, LinkedListSequence<T> seq2) {
    LinkedList<T> arr = this->items->concat(seq1.getItems(), seq2.getItems());
    LinkedListSequence<T> a(arr);
    return a;
}

template<class T>
void LinkedListSequence<T>::reverse() {
    this->items->reverse();
}

#endif //LABA2_LINKEDLISTSEQUENCE_H
