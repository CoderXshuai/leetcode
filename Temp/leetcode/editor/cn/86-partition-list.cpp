#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    ListNode *partition(ListNode *head, int x) {
        auto *l1 = new ListNode();
        auto *l2 = new ListNode();
        auto *p1 = l1;
        auto *p2 = l2;
        while (head != nullptr) {
            if (head->val < x) {
                l1->next = new ListNode(head->val);
                l1 = l1->next;
            } else {
                l2->next = new ListNode(head->val);
                l2 = l2->next;
            }
            head = head->next;
        }
        l1->next = p2->next;
        return p1->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    int arr[] = {1, 4, 3, 2, 5, 2};
    auto *l1 = new ListNode();
    auto *p = l1;
    for (auto &item: arr) {
        p->next = new ListNode(item);
        p = p->next;
    }
    auto head = l1->next;
    s.partition(head, 3);
    cout << "1235";
}