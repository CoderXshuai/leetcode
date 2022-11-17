//
// Created by 14649 on 2022/11/7.
//

#ifndef CPP_LISTNODE_H
#define CPP_LISTNODE_H

class ListNode {


public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

//    bool operator<(const ListNode a) const {
//        return val > a.val; //小顶堆
//    }
};

#endif //CPP_LISTNODE_H
