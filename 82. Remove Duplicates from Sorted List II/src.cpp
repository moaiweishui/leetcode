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
        ListNode* res = head;
        ListNode* p = head;
        ListNode* pre_p = NULL;
	    bool flag = false;
        
        while (p)
	    {
		    ListNode* q = p->next;
		    ListNode* pre_q = p;
		    while (q)
		    {
			    if (q->val == p->val)
			    {
				    pre_q->next = q->next;
				    free(q);
				    flag = true;
				    q = pre_q->next;
			    }
			    else
			    {
				    pre_q = q;
				    q = q->next;
			    }
		    }
		    if (flag)
		    {
			    if (pre_p)
			    {
				    pre_p->next = p->next;
				    free(p);
				    p = pre_p->next;
			    }
			    else
			    {
				    res = res->next;
                    p = res;
			    }
			    flag = false;
		    }
		    else
		    {
			    pre_p = p;
			    p = p->next;
		    }
		
	    }
        
        return res;
        
    }
};
