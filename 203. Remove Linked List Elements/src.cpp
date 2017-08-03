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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head)
            return head;
        else if(!head->next)
        {
            if(head->val == val)
                return NULL;
            else
                return head;
        }
        
        ListNode* node;
        ListNode* prenode = head;

        bool last = false;
	    node = head->next;
	    bool flag = true;
        
        while(node->next)
        {
            while (node->val != val)
		    {
			    prenode = node;
                if (!node->next)
			    {
			    	flag = false;
				    break;
			    }
			    node = node->next;
		    }
            if(!flag)
                break;
            prenode->next = node->next;
		    node = prenode->next;
            if (!node)
		    {
			    last = true;
			    break;
		    }
        }
        
        if (!last && node->val == val)
	    {
		    prenode->next = NULL;
    	}

	    if (head->val == val)
		    return head->next;
        
        return head;
    }
};
