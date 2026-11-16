// Problem: 23. Merge k Sorted Lists
// Difficulty: Hard
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            temp->next = smallest;
            temp = temp->next;
            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }
        temp->next = NULL;
        return dummy.next;
    }
};
