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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
	    ListNode* q = head;
        ListNode* prenode = NULL;
        int len = 0;
        while (p)
	    {
            len++;
		    if (len > n)
            {
                prenode = q;
                q = q->next;
            }			    
		    p = p->next;
	    }
        
        if(q == head)
            return q->next;
        else
        {
            prenode->next = q->next;
            free(q);
            return head;
        }
        
    }
};
