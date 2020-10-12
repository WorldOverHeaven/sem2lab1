#include <iostream>
#include <string>
#include <random>
#include "Sequence.h"
#include "Functions.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "QueueSequence.h"
#include "ISorter.h"
#include "Interface.h"

using namespace std;

int main() {
    int t = 1;
    while (t == 1) {
        auto *a = new Interface<int>;

        a->chooseType();

        a->chooseSize();

        a->chooseSort();

        a->print();

        delete a;

        cout << "Repeat?\n1 if yes" << endl;

        cin >> t;
    }

    return 0;
}
