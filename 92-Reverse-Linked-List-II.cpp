/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tail = head;  // Tail will remain at the original head.

        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return {prev, tail}; // New head is `prev`, and the new tail is the original head.
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) 
            return head;

        ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases.
        dummy->next = head;
        ListNode* leftLL = dummy; // Node before the start of the reversed section.

        // Move `leftLL` to the node before position `left`.
        for (int i = 1; i < left; ++i) {
            leftLL = leftLL->next;
        }

        // `leftStart` points to the start of the section to be reversed.
        ListNode* leftStart = leftLL->next;
        ListNode* rightEnd = leftStart;

        // Move `rightEnd` to the end of the section to be reversed.
        for (int i = left; i < right; ++i) {
            rightEnd = rightEnd->next;
        }

        // `rightLL` is the node after the reversed section.
        ListNode* rightLL = rightEnd->next;

        // Detach the section to be reversed.
        rightEnd->next = NULL;

        // Reverse the section and get the new head and tail.
        auto reversed = reverse(leftStart);

        // Connect the reversed section back to the list.
        leftLL->next = reversed.first;
        reversed.second->next = rightLL;

        // Return the new head.
        return dummy->next;
    }
};