#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "ListNode.h"

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA;
        auto p2 = headB;
        while (p1 != p2) {
            if (p1 == nullptr)
                p1 = headB;
            else
                p1 = p1->next;
            if (p2 == nullptr)
                p2 = headA;
            else
                p2 = p2->next;
        }
        return p1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    int arr[] = {2, 3};
    auto *l1 = new ListNode();
    auto *p = l1;
    for (auto &item: arr) {
        p->next = new ListNode(item);
        p = p->next;
    }
    auto *l2 = new ListNode();
    auto *p2 = l2;
    p2->next = l1->next->next;
    auto res = s.getIntersectionNode(l1->next, l2->next);
    res->val;
}