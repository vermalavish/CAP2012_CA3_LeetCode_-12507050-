// Problem: 61. Rotate List
// Difficulty: Medium
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode* temp = head;
        int count = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        k = k % count;
        if (k == 0) {
            return head;
        }
        temp->next = head;
        int steps = count - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
