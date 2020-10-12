#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "Sequence.h"
std::random_device rd;
using namespace std;

struct complex {
    int real;
    int imagine;
};

template <class T> struct list {
    T data;
    list<T>* next;
};

//////////////////////////////////////////////////////////////////////////////////////

template <class T> class DynamicArray {
private:
    T* head;
    int len = 0;
public:
    DynamicArray() {
        len = 0;
        head = (T*)malloc(sizeof(T));
        head[0] = 0;
    }

    DynamicArray(T* items, int size) {
        len = size;
        head = (T*)malloc(size*sizeof(T));
        for (int i = 0; i < size; ++i) {
            head[i] = items[i];
        }
    }

    explicit DynamicArray(int size) {
        len = size;
        head = (T*)malloc(size*sizeof(T));
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

    DynamicArray(const DynamicArray & obj) {
        len = obj.len;
        head = (T*)malloc(len*sizeof(T));
        for (int i = 0; i < len; ++i) {
            head[i] = obj.head[i];
        }
    }

    ~DynamicArray() {
        free(head);
    }

    int& operator[] (const int index) {
        return head[index];
    }

    int getSize() {
        return len;
    }

    T getElem(int index) {
        if (index < len && index >= 0) {
            return head[index];
        }
        else {
            cout << "IndexOutOfRange" << endl;
        }
    }

    void Set(int index, T value) {
        if (index < len && index >= 0) {
            head[index] = value;
        }
        else {
            cout << "IndexOutOfRange" << endl;
        }
    }

    void resize(int newSize) {
        if (newSize <= 0) {
            cout << "IndexOutOfRange" << endl;
        }
        else {
            T* head2 = (T*)malloc(newSize*sizeof(T));
            if (newSize > len) {
                for (int i = 0; i < len; ++i) {
                    head2[i] = head[i];
                }
                for (int i = len; i < newSize; ++i) {
                    head2[i] = 0;
                }
            }
            else {
                for (int i = 0; i < newSize; ++i) {
                    head2[i] = head[i];
                }
            }
            free(head);
            head = head2;
            len = newSize;
        }
    }

    void print() {
        for (int i = 0; i < len; ++i) {
            cout << head[i] << endl;
        }
    }

    void insertAt(T value, int index) {
        if (index < 0 || index > len) {
            cout << "IndexOutOfRange" << endl;
            return;
        }
        T* head2 = (T*)malloc((len + 1)*sizeof(T));
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

    void removeAt(int index) {
        if (index < 0 || index > len) {
            cout << "IndexOutOfRange" << endl;
            return;
        }
        T* head2 = (T*)malloc((len - 1)*sizeof(T));
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

    DynamicArray<T> getSubSeq(int start, int end) {
        if (start < 0 || start > len || end < 0 || end > len || end < start) {
            cout << "IndexOutOfRange" << endl;
            DynamicArray<T> a;
            return a;
        }
        T* head2 = (T*)malloc((end - start + 1) * sizeof(T));
        for (int i = 0; i < end - start + 1; ++i) {
            head2[i] = head[i + start];
        }
        DynamicArray<T> ab (head2, end - start + 1);
        free(head2);
        return ab;
    }

    DynamicArray<T> concat(DynamicArray<T> seq1, DynamicArray<T> seq2) {
        T* head2 = (T*)malloc((seq1.len + seq2.len) * sizeof(T));
        for (int i = 0; i < seq1.len; ++i) {
            head2[i] = seq1[i];
        }
        for (int i = 0; i < seq2.len; ++i) {
            head2[i + seq1.len] = seq2[i];
        }
        DynamicArray<T> ab (head2, seq1.len + seq2.len);
        free(head2);
        return ab;
    }

    void reverse() {
        T c;
        for (int i = 0; i <= (len) / 2; ++i) {
            c = head[i];
            head[i] = head[len - i - 1];
            head[len - i - 1] = c;
        }
    }

    void swap (T* a, int i, int j) {
        int k = a[i];
        a[i] = a[j];
        a[j] = k;
    }

    void bubbleSort() {
        bool f = true;
        int end = len;
        while (f) {
            f = false;
            for (int i = 0; i < end - 1; ++i) {
                if (head[i] > head[i + 1]) {
                    swap(head, i, i + 1);
                    f = true;
                }
            }
            --end;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////

template <class T> class LinkedList {
private:
    int len;
    list<T>* head;
    void setLen(int i) {
        len = i;
    }
public:
    LinkedList<T>() {
        len = 0;
        head = nullptr;
    }

    LinkedList(const T *items, int size) {
        len = size;
        head = nullptr;
        for (int i = 0; i < size; ++i) {
            auto* nd = new list<T>();
            nd->data = items[size - i - 1];
            nd->next = head;
            head = nd;
        }
    }

    LinkedList(list<T>* lst, int size) {
        len = size;
        head = nullptr;
        for (int i = 0; i < size; ++i) {
            auto* nd = new list<T>();
            nd->next = head;
            head = nd;
        }
        list<T>* head2 = head;
        for (int i = 0; i < size; ++i) {
            head2->data = lst->data;
            head2 = head2->next;
            lst = lst->next;
        }
    }

    explicit LinkedList(int size) {
        len = size;
        head = nullptr;

        cout << "Select how to fill in the array:" << endl;
        cout << "0 - All elements are filled in randomly" << endl;
        cout << "1 - To introduce elements" << endl;
        int a;
        cin >> a;

        if (a == 0) {
            for (int i = 0; i < size; ++i) {
                auto* nd = new list<T>();
                nd->data = rand() % 10;
                nd->next = head;
                head = nd;
            }
            return;
        }

        if (a == 1) {
            for (int i = 0; i < size; ++i) {
                auto* nd = new list<T>();
                cin >> nd->data;
                nd->next = head;
                head = nd;
            }
            return;
        }

        for (int i = 0; i < size; ++i) {
            auto* nd = new list<T>();
            nd->data = 0;
            nd->next = head;
            head = nd;
        }
    }

    LinkedList(const LinkedList & obj) {
        len = obj.len;
        head = nullptr;
        auto* head2 = obj.head;
        T* arr = (T*)malloc(obj.len*(sizeof(T)));
        for (int i = 0; i < len; ++i) {
            arr[i] = head2->data;
            head2 = head2->next;
        }
        for (int i = 0; i < len; ++i) {
            auto* nd = new list<T>();
            nd->data = arr[len - i - 1];
            nd->next = head;
            head = nd;
        }
        free(arr);
    }

    ~LinkedList() {
        list<T>* head2;
        while (head != nullptr) {
            head2 = head->next;
            delete head;
            head = head2;
        }
    }

    void addNode(T d) {
        if (len == 0) {
            ++len;
            auto *nd = new list<T>();
            nd->data = d;
            nd->next = head;
            head = nd;
        }
        else {
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

    int& operator[] (const int index) {
        int i = 0;
        list<T>* head2 = head;
        while (i != index) {
            head2 = head2->next;
            ++i;
        }
        return head2->data;
    }

    T get(int index) {
        int i = 0;
        list<T>* head2 = head;
        if (index >= 0 && index < len) {
            while (i != index) {
                head2 = head2->next;
                ++i;
            }
        }
        return head2->data;
    }

    int getLen() {
        return len;
    }

    LinkedList<T> GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex > len || endIndex < 0 || endIndex > len || endIndex < startIndex) {
            cout << "IndexOutOfRange" << endl;
            LinkedList<T> a;
            return a;
        }
        auto* head3 = head;
        int i = 0;
        while (i != startIndex) {
            head3 = head3->next;
            ++i;
        }
        LinkedList<T> ab (head3, endIndex - startIndex + 1);
        return ab;
    }

    void insert(T value, int index) {
        if (index < 0 || index > len) {
            cout << "IndexOutOfRange" << endl;
            return;
        }
        ++len;
        list<T>* head2 = head;
        int i = 0;
        while (i != index) {
            head2 = head2->next;
            ++i;
        }
        auto* a = new list<T>();
        a->next = head2->next;
        a->data = value;
        head2->next = a;
    }

    void replace(T value, int index) {
        list<T>* head2 = head;
        int i = 0;
        while (i != index) {
            head2 = head2->next;
            ++i;
        }
        head2->data = value;
    }

    void removeFirst() {
        if (len == 0) {
            cout << "IndexOutOfRange" << endl;
            return;
        }
        auto head2 = head;
        head = head->next;
        delete head2;
        --len;
    }

    void removeAt(int index) {
        if (index < 1 || index > len) {
            if (index == 0) {
                removeFirst();
                return;
            }
            cout << "IndexOutOfRange" << endl;
            return;
        }
        --len;
        list<T>* head2 = head;
        int i = 0;
        while (i != index - 1) {
            head2 = head2->next;
            ++i;
        }
        auto head3 = head2->next;
        head2->next = head2->next->next;
        delete head3;
    }

    LinkedList<T> concat(LinkedList<T> list1, LinkedList<T> list2) {
        list<T>* head1 = list1.head;
        list<T>* head2 = list2.head;
        T* arr = (T*)malloc((list1.len + list2.len) * sizeof(T));
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
        LinkedList<T> a (arr, list1.len + list2.len);
        free(arr);
        cout << "len " << list1.len + list2.len << endl;
        return a;
    }

    void print() {
        list<T>* head2 = head;
        for (int i = 0; i < len; ++i) {
            cout << head2->data << endl;
            head2 = head2->next;
        }
    }

    void reverse() {
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

    void swap (int i, int j) {
        int k = get(i);
        replace(get(j), i);
        replace(k, j);
    }

    void bubbleSort() {
        bool f = true;
        int end = len;
        while (f) {
            f = false;
            for (int i = 0; i < end - 1; ++i) {
                if (get(i) > get(i + 1)) {
                    swap(i, i + 1);
                    f = true;
                }
            }
            --end;
        }
    }
};

inline int kvI(int a) {
    return a * a;
}

int rdI(int a, int c) {
    return a / c + a % c + c / a + c % a;
}

complex kvC(complex a) {
    complex b{};
    b.real = a.real * a.real - a.imagine * a.imagine;
    b.imagine = 2 * a.real * a.imagine;
    return b;
}

complex rdC(complex a, complex c) {
    complex b{};
    b.real = a.real + c.real;
    b.imagine = a.imagine - c.imagine;
    return b;
};

//////////////////////////////////////////////////////////////////////////////////////

//template <class T> class Sequence {
//public:
//    virtual int getLen() = 0;
//    virtual T get(int i) = 0;
//
//    virtual void insertAt(int index, T value) = 0;
//    virtual void removeAt(int index) = 0;
//    virtual void print() = 0;
//    virtual ~Sequence() = 0;
//    virtual void addNode(T value) = 0;
//    virtual void reverse() = 0;
//    virtual void bubbleSort() = 0;
//};

template<class T>
Sequence<T>::~Sequence() = default;

//////////////////////////////////////////////////////////////////////////////////////

template <class T> class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* items;
public:
    int& operator[] (const int index) {
        return this->items->operator[](index);
    }

    DynamicArray<T> getItems() const {
        return *items;
    }

    explicit ArraySequence(DynamicArray<T> arr) {
        this->items = new  DynamicArray<T>(arr);
    }

    ArraySequence() {
        this->items = new DynamicArray<T>();
    }

    ArraySequence(T* a, int size) {
        this->items = new DynamicArray<T>(a, size);
    }

    explicit ArraySequence(int size) {
        this->items = new DynamicArray<T>(size);
    }

    ArraySequence(const ArraySequence<T> & obj) {
        this->items = new DynamicArray<T>(obj.getItems());
    }

    ~ArraySequence() override {
        delete items;
    }

    int getLen() override {
        return this->items->getSize();
    }

    T get(int i) override {
        return this->items->operator[](i);
    }

    void insertAt(T value, int index) override {
        this->items->insertAt(value, index);
    }

    void addNode(T value) override {
        this->items->insertAt(value, this->items->getSize());
    }

    void removeAt(int index) override {
        this->items->removeAt(index);
    }

    void print() override {
        this->items->print();
    }

    Sequence<T>* getSub(int start, int end) {
        DynamicArray<T> arr = this->items->getSubSeq(start, end);
        ArraySequence<T> a (arr);
        auto b = &a;
        return b;
    }

    ArraySequence<T> getSubSeq(int start, int end) {
        DynamicArray<T> arr = this->items->getSubSeq(start, end);
        ArraySequence<T> a (arr);
        return a;
    }

    ArraySequence<T> concat(ArraySequence<T> seq1, ArraySequence<T> seq2) {
        DynamicArray<T> arr = this->items->concat(seq1.getItems(), seq2.getItems());
        ArraySequence<T> a (arr);
        return a;
    }

    void reverse() override {
        this->items->reverse();
    }

    void bubbleSort() override {
        this->items->bubbleSort();
    }
};

//////////////////////////////////////////////////////////////////////////////////////

template <class T> class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T>* items;
public:
    int& operator[] (const int index) {
        return this->items->operator[](index);
    }

    LinkedList<T>* getItems() const {
        return items;
    }

    explicit LinkedListSequence(LinkedList<T> arr) {
        this->items = new LinkedList<T>(arr);
    }

    LinkedListSequence() {
        this->items = new LinkedList<T>();
    }

    explicit LinkedListSequence(int size) {
        this->items = new LinkedList<T>(size);
    }

    LinkedListSequence(T* arr, int size) {
        this->items = new LinkedList<T>(arr, size);
    }

    LinkedListSequence(const LinkedListSequence<T> & obj) {
        this->items = new LinkedList<T>(obj.getItems());
    }

    ~LinkedListSequence() override {
        delete items;
    }

    int getLen() override {
        return this->items->getLen();
    }

    T get(int i) override {
        return this->items->operator[](i);
    }

    void addNode(const T value) override {
        this->items->addNode(value);
    }

    void createRandom(int size) {
        for (int i = 0; i < size; ++i) {
            this->addNode(rand() % 100000);
        }
    }

    void insertAt(T value, int index) override {
        this->items->insert(value, index);
    }

    void removeAt(int index) override {
        this->items->removeAt(index);
    }

    void print() override {
        this->items->print();
    }

    LinkedListSequence<T>* getSub(int start, int end) {
        LinkedList<T> arr = this->items->GetSubList(start, end);
        LinkedListSequence<T> a (arr);
        LinkedListSequence<T>* b = &a;
        return b;
    }

    LinkedListSequence<T> getSubSeq(int start, int end) {
        LinkedList<T> arr = this->items->GetSubList(start, end);
        LinkedListSequence<T> a (arr);
        return a;
    }

    LinkedListSequence<T> concat(LinkedListSequence<T> seq1, LinkedListSequence<T> seq2) {
        LinkedList<T> arr = this->items->concat(seq1.getItems(), seq2.getItems());
        LinkedListSequence<T> a (arr);
        return a;
    }

    void reverse() override {
        this->items->reverse();
    }

    void bubbleSort() override {
        this->items->bubbleSort();
    }
};

//////////////////////////////////////////////////////////////////////////////////////

template <class T> class QueueSequence {
private:
    Sequence<T>* items;
    bool tpe;
public:
    QueueSequence() {
        this->items = new ArraySequence<T>();
        tpe = true;
    }

    explicit QueueSequence(bool b) {
        tpe = b;
        if (b) {
            this->items = new ArraySequence<T>();
        }
        else {
            this->items = new LinkedListSequence<T>();
        }
    }

    Sequence<T>* getItems() const {
        return items;
    }

    QueueSequence(const QueueSequence<T> & obj) {
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

    ~QueueSequence() {
        delete items;
    }

    void addNode(const T value) {
        this->items->addNode(value);
    }

    T get() {
        T c = this->items->get(0);
        this->items->removeAt(0);
        return c;
    }

    int getLen() const {
        return this->items->getLen();
    }

    QueueSequence<T> getSub(int start, int end) {
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

    QueueSequence<T> concat(QueueSequence<T> q1, QueueSequence<T> q2) {
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

    QueueSequence<T> map(T (*function) (T)) {
        QueueSequence<T> a;
        int len = this->items->getLen();
        for (int i = 0; i < len; ++i) {
            a.addNode(function(this->items->get(i)));
        }
        return a;
    }

    void reverse() {
        this->items->reverse();
    }

    T reduce(T (*function) (T, T), T c) {
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

    void print() {
        this->items->print();
    }

    void printComplex() {
        this->items->printComplex();
    }
};

//////////////////////////////////////////////////////////////////////////////////////

int main() {

    bool bl = false;

    LinkedListSequence<int> a;

    a.createRandom(10000);

    //a.print();

    a.bubbleSort();

    //a.print();

    return 0;
}
