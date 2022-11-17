自己的方法

```c++
public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
```

大佬的方法，根据LeetCode中链表的内存是连续申请的，如果有环，则必存在head->next一定小于或等于head

```c++
public:
    ListNode *detectCycle(ListNode *head) {
        while(head) {
            if(!less<ListNode *>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};
```