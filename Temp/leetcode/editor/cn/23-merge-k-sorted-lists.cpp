#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include "ListNode.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        priority_queue<ListNode> queue;
        auto *res = new ListNode();
        auto *p = res;
        for (auto &item: lists) {
            queue.push(*item);
        }
        while (!queue.empty()) {
            ListNode top = queue.top();
            p->next = new ListNode(top.val);
            if (top.next != nullptr) {
                queue.push(*top.next);
            }
            queue.pop();
            p = p->next;
        }

        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    int arr[] = {1, 4, 5};
    auto *l1 = new ListNode();
    auto *p = l1;
    for (auto &item: arr) {
        p->next = new ListNode(item);
        p = p->next;
    }
    int arr2[] = {1, 3, 4};
    auto *l2 = new ListNode(0, l1);
    p = l2;
    for (auto &item: arr2) {
        p->next = new ListNode(item);
        p = p->next;
    }
    auto lists = vector<ListNode *>();
    lists.push_back(l1);
    lists.push_back(l2);
    s.mergeKLists(lists);
}