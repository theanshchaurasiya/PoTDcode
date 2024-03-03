class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = -1;

        function<void(ListNode *)> traverse = [&](ListNode * node) {
            if(!node)
                return;

            traverse(node -> next);
            ++pos;

            if(pos == n) {
                node -> next = node -> next -> next;
            }
        };

        traverse(head);
        ++pos;

        return pos == n ? head -> next : head;
    }
};