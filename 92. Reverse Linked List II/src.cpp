class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(1);
        new_head->next = head;
    
        ListNode* pre = NULL;
        ListNode* curr = new_head;

        for(int i = 0; i < m; i++){
            pre = curr;
            curr = curr->next;
        }
        
        ListNode* tail = curr;
        ListNode* n_node = curr->next;
        ListNode* nn_node;
        int index = m;
        while(n_node != NULL && index < n){
            pre->next = n_node;
            nn_node = n_node->next;
            n_node->next = curr;
            
            tail->next = nn_node;
            
            curr = pre->next;
            n_node = nn_node;
            index++;
        }
        
        return new_head->next;
    }
};
