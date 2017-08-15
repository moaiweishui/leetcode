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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode* head = l1;

        ListNode* p = l2;
        
        while (p)
        {
            ListNode* q = head;
            ListNode* preq = NULL;
            bool flag = false;
            while (q)
            {
                if (q->val > p->val)
                {
                    flag = true;
                    ListNode* tmp = p;
                    p = p->next;
                    if (preq)
                    {
                        tmp->next = q;
                        preq->next = tmp;
                    }
                    else
                    {
                        tmp->next = q;
                        head = tmp;
                    }
                    break;
                }
                preq = q;
                q = q->next;
            }
            if (!flag)
            {
                ListNode* tmp = p;
                p = p->next;
                preq->next = tmp;
                tmp->next = NULL;
            }
        }
        
        return head;
        
    }
};
