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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* curr = head;
        ListNode* nextNode = head->next;
        ListNode* newHead = nextNode;
        ListNode* temp = NULL;        

        while(curr && nextNode) {
            curr->next = nextNode->next;
            nextNode->next = curr;

            if(temp)
                temp->next = nextNode;

            temp = curr;

            curr = curr->next;
            if(curr)
                nextNode = curr->next;
        }

        return newHead;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
