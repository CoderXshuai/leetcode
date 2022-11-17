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
    ListNode *deleteDuplicates(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast != nullptr) {
            if (slow != fast) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
}