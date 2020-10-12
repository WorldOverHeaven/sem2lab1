#ifndef LABA2_SEQUENCE_H
#define LABA2_SEQUENCE_H


template<class T>
class Sequence {
public:
    virtual void swap(int i, int j) = 0;

    virtual int getLen() = 0;

    virtual T get(int i) = 0;

    virtual void insertAt(int index, T value) = 0;

    virtual void removeAt(int index) = 0;

    virtual void print() = 0;

    virtual ~Sequence() = 0;

    virtual void addNode(T value) = 0;

    virtual void reverse() = 0;

    virtual void create(int size) = 0;

    virtual void createRandom(int size) = 0;

    virtual void replace(T value, int index) = 0;
};

template<class T>
Sequence<T>::~Sequence() = default;

#endif //LABA2_SEQUENCE_H
