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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while (head) {
            if (!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
    int arr[] = {3, 2, 0, -4};
    auto *l1 = new ListNode();
    auto *p = l1;
    for (auto &item: arr) {
        p->next = new ListNode(item);
        p = p->next;
    }
    p->next = l1->next->next;
    s.detectCycle(l1->next);
}