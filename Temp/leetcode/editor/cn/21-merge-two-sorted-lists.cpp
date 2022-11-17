#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode res = ListNode();
        ListNode *temp = &res;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr)
            temp->next = list1;
        if (list2 != nullptr)
            temp->next = list2;
        return (&res)->next;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s = Solution();
    auto *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    auto *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    s.mergeTwoLists(l1, l2);
    cout << "123";
    return 0;
}