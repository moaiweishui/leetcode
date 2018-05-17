class Solution {
public:
    pair<ListNode*, ListNode*> find_last_k(ListNode* head, int k){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while (k){
            fast = fast->next;
            k--;
        }

        ListNode* last = NULL;
        while (fast != NULL){
            last = fast;
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }

        return make_pair(pre, last);
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = 0;
        ListNode* p = head;

        while (p != NULL){
            len++;
            p = p->next;
        }

        k = k % len;
        if (k == 0) return head;

        pair<ListNode*, ListNode*> pair = find_last_k(head, k);
        ListNode* new_head = (pair.first)->next;
        ListNode* last = pair.second;
        (pair.first)->next = NULL;
        last->next = head;
        return new_head;
    }
};
