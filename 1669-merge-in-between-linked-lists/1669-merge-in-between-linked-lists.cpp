class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * b_head = list2;
        ListNode * b_tail = list2;

        while(b_tail -> next != nullptr)
            b_tail = b_tail -> next;

        ListNode * cur = list1;

        int index = 0;

        while(index != a - 1)
            cur = cur -> next,++index;

        ListNode * last = cur;
        cur = cur -> next;
        ++index;
        last -> next = b_head;

        while(index != b)
            cur = cur -> next, ++index;

        b_tail -> next = cur -> next;

        return list1;
    }
};