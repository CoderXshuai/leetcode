Set存储法

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> mySet;
        set<ListNode *>::iterator it;
        while (headA != nullptr && headB != nullptr) {
            it = mySet.find(headA);
            if (it == mySet.end())
                mySet.emplace(headA);
            else
                return headA;
            it = mySet.find(headB);
            if (it == mySet.end())
                mySet.emplace(headB);
            else
                return headB;
            headA = headA->next;
            headB = headB->next;
        }
        while (headA != nullptr) {
            it = mySet.find(headA);
            if (it == mySet.end())
                mySet.emplace(headA);
            else
                return headA;
            headA = headA->next;
        }
        while (headB != nullptr) {
            it = mySet.find(headB);
            if (it == mySet.end())
                mySet.emplace(headB);
            else
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
```

两链表合并，再遍历

```c++
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
```