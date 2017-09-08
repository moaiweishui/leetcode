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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return head;
        ListNode* new_head = head;
        ListNode* p = head;
        ListNode* prep = NULL;
        
        vector<ListNode*> vec;
        
        while(p)
        {
            if (p->val >= x)
            {
                ListNode* tmp = new ListNode(p->val);
                vec.push_back(tmp);
                
                if (prep == NULL)
                {
                    new_head = p->next;
                    free(p);
                    p = new_head;
                }
                else
                {
                    prep->next = p->next;
                    free(p);
                    p = prep->next;
                }
            }
            else
            {
                prep = p;
                p = p->next;
            }
        }
        
        if(vec.size() == 0)
            return new_head;
        
        if(prep == NULL)
        {
            new_head = vec[0];
            for(int i = 1; i < vec.size(); i++)
            {
                vec[i - 1]->next = vec[i];
                if(i == vec.size() - 1)
                    vec[i]->next = NULL;
            }
        }
        else
        {
            prep->next = vec[0];
            for(int i = 1; i < vec.size(); i++)
            {
                vec[i - 1]->next = vec[i];
                if(i == vec.size() - 1)
                    vec[i]->next = NULL;
            }
        }
        return new_head;
    }
};
