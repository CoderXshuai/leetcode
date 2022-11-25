```c++
public:
    ListNode *deleteDuplicates(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast != nullptr) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        if (slow != nullptr)
            slow->next = fast;
        return head;
    }
```