/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedSubListToBST(ListNode* start, ListNode* end){
        if(start == end) return NULL;
        if (start->next == end) return new TreeNode(start->val);

        ListNode* fast = start;
        ListNode* slow = start;

        // 
        while (fast != end && fast->next != end){
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedSubListToBST(start, slow);
        node->right = sortedSubListToBST(slow->next, end);

        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        else if (head->next == NULL) return new TreeNode(head->val);

        return sortedSubListToBST(head, NULL);
    }
};
