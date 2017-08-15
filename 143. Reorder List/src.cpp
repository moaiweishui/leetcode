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
    void reorderList(ListNode* head) {
        ListNode* p = head;
        if(p == NULL)
            return;
	    ListNode* q = head->next;
        if(q == NULL)
            return;
        else if(q->next == NULL)
            return;
        
        while (1)
	    {
		    ListNode* tail = p;
		    ListNode* pretail = p;
		    while (tail->next)
		    {   
			    pretail = tail;
			    tail = tail->next;
		    }

		    p->next = tail;
		    tail->next = q;
		    pretail->next = NULL;

		    p = q;
		    q = p->next;
		    if (q == NULL || q->next == NULL)
			    break;
	    }
        
        
    }
};
