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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        auto fast = head;
        auto slow = head;
        for (int i = 0; i < k - 1; ++i)
            fast = fast->next;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s = Solution();
}