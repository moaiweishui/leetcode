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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
	    vector<int> v2;
        ListNode* p = l1;
        while (p)
	    {
		    v1.push_back(p->val);
		    p = p->next;
	    }
        
        p = l2;
        while (p)
	    {
		    v2.push_back(p->val);
		    p = p->next;
	    }
        
        int len1 = v1.size();
	    int len2 = v2.size();
        
        if (len1 > len2)
	    {
		    for (int i = 0; i < len1 - len2; i++)
		    {
			    v2.push_back(0);
		    }
	    }
	    else if (len1 < len2)
	    {
		    for (int i = 0; i < len2 - len1; i++)
		    {
			    v1.push_back(0);
		    }
	    }
        
        int c = 0;
	    ListNode* lastnode = NULL;
        ListNode* head = NULL;
	    for (int i = 0; i < v1.size(); i++)
	    {
		    int sum = v1[i] + v2[i] + c;
		    if (sum >= 10)
		    {
			    sum = sum % 10;
			    c = 1;
		    }
		    else
		    {
			    c = 0;
		    }
		    ListNode* new_node = new ListNode(sum);
		    if (lastnode)
			    lastnode->next = new_node;
		    else
			    head = new_node;
		    lastnode = new_node;
	    }

	    if (c)
	    {
		    ListNode* new_node = new ListNode(1);
		    lastnode->next = new_node;
	    }
        
        return head;
        
    }
};
