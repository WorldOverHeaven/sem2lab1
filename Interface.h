#ifndef LABA2_INTERFACE_H
#define LABA2_INTERFACE_H
#include <iostream>
#include "ISorter.h"
#include <ctime>
using namespace std;

template <class T>
class Interface {
private:
    Sequence<T> *items;
    ISorter<T> *sorter;
public:
    void chooseType() {
        cout << "Choose\n0 - array\n1 - list" << endl;
        int t;
        cin >> t;
        if (t == 0) {
            items = new LinkedListSequence<T>;
        }
        if (t == 1) {
            items = new ArraySequence<T>;
        }
    }

    void chooseSize() {
        cout << "Enter size of sequence" << endl;
        int s;
        cin >> s;
        cout << "Choose\n0 - manually\n1 - random" << endl;
        int k;
        cin >> k;
        if (k == 0) {
            this->items->create(s);
        }
        else {
            this->items->createRandom(s);
        }
    }

    void chooseSort() {
        cout << "0 - bubbleSort\n"
                "1 - shakerSort\n"
                "2 - insertionSort\n"
                "3 - shellSort\n"
                "4 - shellDataSort\n"
                "5 - countingSort\n"
                "6 - pirSort" << endl;
        int t;
        cin >> t;
        if (t == 0) {
            sorter = new BubbleSorter<T>;
        }
        if (t == 1) {
            sorter = new ShakerSorter<T>;
        }
        if (t == 2) {
            sorter = new InsertionSorter<T>;
        }
        if (t == 3) {
            sorter = new ShellSorter<T>;
        }
        if (t == 4) {
            sorter = new ShellDataSorter<T>;
            cout << "choose 2 numbers" << endl;
            int aa, bb;
            cin >> aa >> bb;
            int tt = clock();
            dynamic_cast<ShellDataSorter<T>*>(sorter)->sort(items, aa, bb);
            //print();
            cout << "time " << clock() - tt << endl;
            return;
        }
        if (t == 5) {
            sorter = new CountingSorter<T>;
        }
        if (t == 6) {
            sorter = new PirSorter<T>;
        }

        int tt = clock();
        sorter->sort(items);
        //print();
        cout << "time " << clock() - tt << endl;
    }

    void print() {
        items->print();
    }
};

#endif //LABA2_INTERFACE_H
