#ifndef LABA2_FUNCTIONS_H
#define LABA2_FUNCTIONS_H

#include <vector>
#include <algorithm>
using namespace std;

struct complex {
    int real;
    int imagine;
};

template<class T>
struct list {
    T data;
    list<T> *next;
};

inline int kvI(int a);

int rdI(int a, int c);

complex kvC(complex a);

complex rdC(complex a, complex c);

////////////////////////////////////////

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

bool check(int n, int a, int b) {
    while (n % a == 0) {
        n /= a;
    }
    while (n % b == 0) {
        n /= b;
    }
    return (n == 1);
}

vector <int> makeData(int n, int a, int b) {
    vector <int> arr;
    for (int i = n; i >= 1; --i) {
        if (check(i, a, b)) {
            arr.push_back(i);
        }
    }
    return arr;

}

vector <int> makeDataFib(int n) {
    vector <int> a;
    int b = 1;
    int c = 2;
    while (b < n) {
        a.push_back(b);
        int d = b + c;
        b = c;
        c = d;
    }
    reverse(a.begin(), a.end());
    return a;
}

#endif //LABA2_FUNCTIONS_H
