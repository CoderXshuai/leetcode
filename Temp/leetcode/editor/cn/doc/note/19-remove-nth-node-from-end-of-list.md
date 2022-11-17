虚拟头结点的方法

```c++
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
```

不采用虚拟头结点，单独对删除第一个节点进行处理

```c++
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto fast = head;
        auto slow = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        if (fast == nullptr)
            head=head->next;
        else {
            while (fast->next != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
        }
        return head;
    }
```
