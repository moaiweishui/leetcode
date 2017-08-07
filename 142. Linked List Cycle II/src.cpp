/******************** Solution 1 *****************************/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1 = head;
	    int step1 = 0;
	    int pos = -1;
        
        while(p1)
        {
            ListNode* p2 = head;
		    int step2 = 0;
            
            while(p2)
            {
                if(p2 == p1)
                    if(step2 != step1)
                        return p2;
                    else
                        break;
                else
                {
                    p2 = p2->next;
                    step2++;
                } 
            }
            p1 = p1->next;
            step1++;
        }
        
        return NULL;
    }
};
