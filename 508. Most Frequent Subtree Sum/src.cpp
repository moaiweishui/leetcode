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
    int subTreeSum(TreeNode* node){
	    int res = 0;
        if (node)
	    {
		    res += node->val;
		    if (node->left)
		    {
			    res += subTreeSum(node->left);
		    }
		    if (node->right)
		    {
			    res += subTreeSum(node->right);
		    }
		    return res;
	    }
	    else
		    return res;
    }
    
    void displayTree(TreeNode* node, multiset<int>& mset){
	    if (node)
	    {
		    mset.insert(subTreeSum(node));
		    if (node->left)
		    {
			    displayTree(node->left, mset);
		    }
		    if (node->right)
		    {
			    displayTree(node->right, mset);
		    }
	    }
	    else
		    return;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        multiset<int> m_set;
	    displayTree(root, m_set);
        multiset<int>::iterator it;
        int fre = 0;
	    for (it = m_set.begin(); it != m_set.end(); it++)
	    {
		    if (m_set.count(*it) > fre)
			    fre = m_set.count(*it);
	    }
	    vector<int> v;
	    vector<int>::iterator v_it;
        
        for (it = m_set.begin(); it != m_set.end(); it++)
            if (m_set.count(*it) == fre)
            {
                v_it = find(v.begin(), v.end(), *it);
                if (v_it == v.end())
                    v.push_back(*it);
            }
        return v;
    }
};
