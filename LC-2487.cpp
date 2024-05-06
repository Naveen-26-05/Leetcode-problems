class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) return NULL;
        head->next = removeNodes(head->next);
        return (head->next && head->val < head->next->val) ? head->next : head;
    }
};
