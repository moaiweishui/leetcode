/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode* new_head = head;
        ListNode* current = new_head;
        
        while (current->next)
        {
            ListNode* tmp = new ListNode(current->next->val);
            tmp->next = new_head;
            if(current->next->next)
            {
                current->next = current->next->next;
            }
            else
            {
                current->next = NULL;
            }
            new_head = tmp;
        }
        return new_head;
        
    }
};
