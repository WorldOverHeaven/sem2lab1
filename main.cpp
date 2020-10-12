#include <iostream>
#include "Sequence.h"
#include "Functions.h"
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
