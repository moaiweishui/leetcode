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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL)
            return NULL;
        
        ListNode* p = head;
        
        ListNode* prep = NULL;
        
        if (p->next == NULL)
            return head;
        else
            head = p->next;
        
        while (p->next)
        {
            ListNode* temp = p->next;

            p->next = temp->next;
            temp->next = p;
            if (prep)
                prep->next = temp;

            if (p->next == NULL)
                break;
            prep = p;
            p = p->next;
        }
        return head;
    }
};
