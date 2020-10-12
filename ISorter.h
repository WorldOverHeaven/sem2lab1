#ifndef LABA2_ISORTER_H
#define LABA2_ISORTER_H

#include "Sequence.h"
#include "Functions.h"

template<class T>
class ISorter {
public:
    virtual Sequence<T>* sort(Sequence<T>*) = 0;
    virtual ~ISorter() = default;
};

template<class T>
class BubbleSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
private:
    Sequence<T>* data;
};

template<class T>
Sequence<T>* BubbleSorter<T>::sort(Sequence<T> * a) {
    data = a;
    bool f = true;
    int end = data->getLen();
    if (end == 0) {
        return data;
    }
    while (f) {
        f = false;
        for (int i = 0; i < end - 1; ++i) {
            if (data->get(i) > data->get(i + 1)) {
                data->swap(i, i + 1);
                f = true;
            }
        }
        --end;
    }
    return data;
}


template<class T>
class ShakerSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
private:
    Sequence<T>* data;
};

template<class T>
Sequence<T>* ShakerSorter<T>::sort(Sequence<T> * a) {
    data = a;
    int beg = 0;
    int end = data->getLen();
    if (end == 0) {
        return data;
    }
    bool f = true;
    while (f) {
        f = false;
        for (int i = 0; i < end - 1; ++i) {
            if (data->get(i) > data->get(i + 1)) {
                data->swap(i, i + 1);
                f = true;
            }
        }
        --end;
        for (int i = end; i > beg; --i) {
            if (data->get(i - 1) > data->get(i)) {
                data->swap(i - 1, i);
                f = true;
            }
        }
        ++beg;
    }
    return data;
}


template<class T>
class InsertionSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
private:
    Sequence<T>* data;
};

template<class T>
Sequence<T>* InsertionSorter<T>::sort(Sequence<T> * a) {
    data = a;
    auto len = data->getLen();
    if (len == 0) {
        return data;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (data->get(i) > data->get(j)) {
                data->swap(i, j);
            }
        }
    }
    return data;
}

template<class T>
class ShellSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
private:
    Sequence<T>* data;
};

template<class T>
Sequence<T>* ShellSorter<T>::sort(Sequence<T> * a) {
    data = a;
    int n = data->getLen();
    if (n == 0) {
        return data;
    }
    auto data2 = makeData(n, 3, 5);
    for (int i : data2) {
        int end = n - i;
        int beg = 0;
        while (beg < i) {
            bool f = true;
            while (f) {
                f = false;
                for (int j = beg; j < end; j += i) {
                    if (data->get(j) > data->get(j + i)) {
                        data->swap(j, j + i);
                        f = true;
                    }
                }
            }
            ++beg;
        }
    }
    return data;
}


template<class T>
class ShellDataSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
    Sequence<T>* sort(Sequence<T>* a, int j, int k);
private:
    Sequence<T>* data;
    int c = 3, d = 5;
};

template<class T>
Sequence<T>* ShellDataSorter<T>::sort(Sequence<T> * a) {
    data = a;
    int n = data->getLen();
    if (n == 0) {
        return data;
    }
    auto data2 = makeData(n, 3, 5);
    for (int i : data2) {
        int end = n - i;
        int beg = 0;
        while (beg < i) {
            bool f = true;
            while (f) {
                f = false;
                for (int j = beg; j < end; j += i) {
                    if (data->get(j) > data->get(j + i)) {
                        data->swap(j, j + i);
                        f = true;
                    }
                }
            }
            ++beg;
        }
    }
    return data;
}

template<class T>
Sequence<T>* ShellDataSorter<T>::sort(Sequence<T> * a, int jj, int kk) {
    data = a;
    int n = data->getLen();
    if (n == 0) {
        return data;
    }
    auto data2 = makeData(n, jj, kk);
    for (int i : data2) {
        int end = n - i;
        int beg = 0;
        while (beg < i) {
            bool f = true;
            while (f) {
                f = false;
                for (int j = beg; j < end; j += i) {
                    if (data->get(j) > data->get(j + i)) {
                        data->swap(j, j + i);
                        f = true;
                    }
                }
            }
            ++beg;
        }
    }
    return data;
}

template<class T>
class CountingSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
private:
    Sequence<T>* data;
};

template<class T>
Sequence<T>* CountingSorter<T>::sort(Sequence<T> * a) {
    data = a;
    int n = data->getLen();
    if (n == 0) {
        return data;
    }
    int min (a->get(0)), max (a->get(0));
    for (int i = 0; i < n; ++i) {
        int c = a->get(i);
        if (min > c) {
            min = c;
        }
        if (max < c) {
            max = c;
        }
    }
    int size = max - min;
    T *arr = (T*)malloc(size * sizeof(T));
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++arr[data->get(i)];
    }
    int f = 0;
    for (int i = 0; i < size; ++i) {
        while (arr[i] != 0) {
            data->replace(i, f);
            ++f;
            --arr[i];
        }
    }
    free(arr);
    return data;
}

template<class T>
class PirSorter : public ISorter<T> {
public:
    Sequence<T>* sort(Sequence<T>* a) override;
private:
    Sequence<T>* data;
};

template<class T>
Sequence<T>* PirSorter<T>::sort(Sequence<T> * a) {
    data = a;
    int n = data->getLen();
    if (n == 0) {
        return data;
    }
    int k = 0;
    while (k < n) {
        for (int i = n - 1; i >= k; --i) {
            int j = i - k;
            while (j > 0) {
                j /= 2;
                if (data->get(i) < data->get(j + k)) {
                    data->swap(i, j + k);
                }
            }
        }
        ++k;
    }
    return data;
}
#endif //LABA2_ISORTER_H
