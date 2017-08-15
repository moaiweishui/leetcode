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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p)
	    {
		    ListNode* q = p->next;
		    ListNode* preq = p;
		    while (q)
		    {
			    if (q->val == p->val)
			    {
				    preq->next = q->next;
				    free(q);
				    q = preq->next;
			    }
			    else
			    {
				    preq = q;
				    q = q->next;
			    }
		    }
		    p = p->next;
	    }
        
        return head;
    }
};
