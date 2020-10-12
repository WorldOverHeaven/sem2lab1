#ifndef LABA2_QUEUESEQUENCE_H
#define LABA2_QUEUESEQUENCE_H

#include "Functions.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"


template <class T> class QueueSequence {
private:
    Sequence<T>* items;
    bool tpe;
public:
    QueueSequence();

    explicit QueueSequence(bool b);

    Sequence<T>* getItems() const;

    QueueSequence(const QueueSequence<T> & obj);

    ~QueueSequence();

    void addNode(T value);

    T get();

    int getLen() const;

    QueueSequence<T> getSub(int start, int end);
    QueueSequence<T> concat(QueueSequence<T> q1, QueueSequence<T> q2);

    QueueSequence<T> map(T (*function) (T));

    void reverse();
    T reduce(T (*function) (T, T), T c);

    void print();

    void printComplex();
};

template<class T>
QueueSequence<T>::QueueSequence() {
        this->items = new ArraySequence<T>();
        tpe = true;
    }
template<class T>
QueueSequence<T>::QueueSequence(bool b) {
        tpe = b;
        if (b) {
            this->items = new ArraySequence<T>();
        }
        else {
            this->items = new LinkedListSequence<T>();
        }
    }
template<class T>
    Sequence<T>* QueueSequence<T>::getItems() const {
        return items;
    }
template<class T>
QueueSequence<T>::QueueSequence(const QueueSequence<T> & obj) {
        if (obj.tpe) {
            this->items = new ArraySequence<T>();
        }
        else {
            this->items = new LinkedListSequence<T>();
        }
        tpe = obj.tpe;
        int len = obj.getLen();
        for (int i = 0; i < len; ++i) {
            this->addNode(obj.items->get(i));
        }
    }
template<class T>
QueueSequence<T>::~QueueSequence() {
        delete items;
    }
template<class T>
    void QueueSequence<T>::addNode(const T value) {
        this->items->addNode(value);
    }
template<class T>
    T QueueSequence<T>::get() {
        T c = this->items->get(0);
        this->items->removeAt(0);
        return c;
    }
template<class T>
    int QueueSequence<T>::getLen() const {
        return this->items->getLen();
    }
template<class T>
    QueueSequence<T> QueueSequence<T>::getSub(int start, int end) {
        QueueSequence<T> a;
        int len = this->items->getLen();
        if (start < 0) {
            start = 0;
        }
        if (end >= len) {
            end = len - 1;
        }
        for (int i = start; i <= end; ++i) {
            a.addNode(this->items->get(i));
        }
        return a;
    }
template<class T>
    QueueSequence<T> QueueSequence<T>::concat(QueueSequence<T> q1, QueueSequence<T> q2) {
        QueueSequence<T> a;
        int len = q1.items->getLen();
        for (int i = 0; i < len; ++i) {
            a.addNode(q1.items->get(i));
        }
        len = q2.items->getLen();
        for (int i = 0; i < len; ++i) {
            a.addNode(q2.items->get(i));
        }
        return a;
    }
template<class T>
    QueueSequence<T> QueueSequence<T>::map(T (*function) (T)) {
        QueueSequence<T> a;
        int len = this->items->getLen();
        for (int i = 0; i < len; ++i) {
            a.addNode(function(this->items->get(i)));
        }
        return a;
    }
template<class T>
    void QueueSequence<T>::reverse() {
        this->items->reverse();
    }
template<class T>
    T QueueSequence<T>::reduce(T (*function) (T, T), T c) {
        T a;
        int len = this->getLen();
        if (len == 0) {
            return function(c, c);
        }
        a = function(this->items->get(0), c);
        for (int i = 0; i < len; ++i) {
            a = function (this->items->get(0), a);
        }
        return a;
    }
template<class T>
    void QueueSequence<T>::print() {
        this->items->print();
    }
template<class T>
    void QueueSequence<T>::printComplex() {
        this->items->printComplex();
    }

#endif //LABA2_QUEUESEQUENCE_H
