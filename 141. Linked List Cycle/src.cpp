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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
	    ListNode* slow = head;

	    int cnt = 0;

	    while (fast)
	    {
		    if (cnt % 2 == 1)
			    slow = slow->next;
		    fast = fast->next;
		    cnt++;
		    if (fast == slow)
			    return true;
	    }
	    return false;
    }
};
