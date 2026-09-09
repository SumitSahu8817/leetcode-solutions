class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        int ans = 0;

        ListNode* first = head;
        ListNode* sec = prev;
        while (sec != NULL) {
            ans = max(ans , first->val+sec->val);
            first = first->next;
            sec = sec->next;
        }
        return ans;
    }
};