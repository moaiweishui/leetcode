class Solution {
public:
    ListNode* find_mid(ListNode* head){
        ListNode* pre = NULL;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL && slow != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        ListNode* p = head1;
        ListNode* q = head2;
        while (p != NULL && q != NULL){
            if (p->val < q->val){
                curr->next = p;
                p = p->next;
            }
            else{
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        if (p != NULL) curr->next = p;
        if (q != NULL) curr->next = q;
        return head->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* mid = find_mid(head);

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
    
        return merge(left, right);
    }
};
