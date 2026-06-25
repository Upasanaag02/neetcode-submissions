class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* left = &dummy;
        ListNode* right = &dummy;

        for(int i = 0; i < n; i++) {
            right = right->next;
        }

        while(right->next != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy.next;
    }
};