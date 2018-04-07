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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val < b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        else if (lists.size() == 1) return lists[0];
        multiset<ListNode*, cmp> candidate_set;
        for (int i = 0; i < lists.size(); i++){
            if (lists[i] != NULL) candidate_set.insert(lists[i]);
        }

        ListNode* root = new ListNode(-1);
        ListNode* curr_node = root;
        ListNode* new_node;

        while (!candidate_set.empty()){
            new_node = *candidate_set.begin();
            curr_node->next = new_node;
            candidate_set.erase(candidate_set.begin());
            curr_node = new_node;
            if (curr_node->next != NULL) candidate_set.insert(curr_node->next);
        }
        return root->next;
    }
};
