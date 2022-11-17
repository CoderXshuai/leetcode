//
// Created by 14649 on 2022/11/9.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#ifndef CPP_MAXPQ_H
#define CPP_MAXPQ_H


class MaxPQ {
private:
    vector<int> pq;
    int size = 0;

    bool less(int i, int j);

public:
    MaxPQ(int cap) {
        pq = vector<int>(cap + 1);
        size = cap;
    }

    int max() {
        return pq[1];
    }

    void insert(int i);

    int delMax();

    void swim(int x);

    void sink(int x);

    void swap(int i, int j);

    int parent(int root);

    int left(int root);

    int right(int root);

};


#endif //CPP_MAXPQ_H
