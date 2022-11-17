//
// Created by 14649 on 2022/11/9.
//

#include "MaxPQ.h"

void MaxPQ::insert(int i) {
    size++;
    pq.push_back(i);
    swim(i);
}

int MaxPQ::delMax() {
    int max = pq[1];
    swap(1, size);
    size--;
    sink(pq[1]);
    return max;
}

bool MaxPQ::less(int i, int j) {
    return pq[i] < pq[j];
}

void MaxPQ::swim(int x) {
    while (x > 1 && less(parent(x), x)) {
        swap(x, parent(x));
        x = parent(x);
    }
}

void MaxPQ::sink(int x) {
    while (x < size) {
        int max = left(x);
        if (right(x) < size) {
            if (less(max, right(x))) {
                max = right(x);
            }
        }
        if (less(max, x)) {
            break;
        }
        swap(x, max);
        x = max;
    }
}

void MaxPQ::swap(int i, int j) {
    int temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}

int MaxPQ::parent(int root) {
    return root / 2;
}

int MaxPQ::left(int root) {
    return 2 * root;
}

int MaxPQ::right(int root) {
    return 2 * root + 1;
}
