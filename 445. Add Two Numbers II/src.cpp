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
    void list2vector(ListNode* l1, vector<int>& v)
    {
        while(l1->next)
        {
            v.push_back(l1->val);
            l1 = l1->next;
        }
        v.push_back(l1->val);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> xv;
	    vector<int> yv;
        
        list2vector(l1, xv);
	    list2vector(l2, yv);
	
	    vector<int> num1_v, num2_v;

	    int len;
        
        if (xv.size() >= yv.size())
	    {
		    num1_v.assign(xv.rbegin(), xv.rend());
		    num2_v.assign(yv.rbegin(), yv.rend());
		    len = yv.size();
	    }
	    else
	    {
		    num1_v.assign(yv.rbegin(), yv.rend());
		    num2_v.assign(xv.rbegin(), xv.rend());
		    len = xv.size();
	    }
        
        int c = 0;
	    vector<ListNode*> res_v;
	    for (int i = 0; i < len; i++)
	    {
		    int sum = num1_v[i] + num2_v[i] + c;
		    if (sum >= 10)
		    {
			    sum = sum % 10;
			    c = 1;
		    }
		    else
		    {
			    c = 0;
		    }
		    ListNode* tmp = new ListNode(sum);
		    res_v.push_back(tmp);
	    }
        
        for (int i = len; i < num1_v.size(); i++)
	    {
		    int sum = num1_v[i] + c;
		    if (sum >= 10)
		    {
			    sum = sum % 10;
			    c = 1;
		    }
		    else
		    {
			    c = 0;
		    }
		    ListNode* tmp = new ListNode(sum);
		    res_v.push_back(tmp);
	    }

	    if (c != 0)
	    {
		    ListNode* tmp = new ListNode(1);
		    res_v.push_back(tmp);
	    }

	    for (int i = res_v.size() - 1; i > 0; i--)
	    {
		    res_v[i]->next = res_v[i - 1];
	    }
        
        return res_v[res_v.size()-1];
        
    }
};
