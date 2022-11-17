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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto temp = ListNode(-1);
        temp.next = head;
        auto fast = &temp;
        auto slow = &temp;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return temp.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    int arr[] = {1, 2, 3};
    auto *l1 = new ListNode();
    auto *p = l1;
    for (auto &item: arr) {
        p->next = new ListNode(item);
        p = p->next;
    }
    s.removeNthFromEnd(l1->next, 3);
}