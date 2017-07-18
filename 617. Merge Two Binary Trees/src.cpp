#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{	
	if (t1 && t2)
	{
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
	else if(t1)
		return t1;
	else if (t2)
		return t2;
	else
		return NULL;
}

void main()
{
	TreeNode* t1 = &TreeNode(1);
	t1->left = &TreeNode(3);
	t1->right = &TreeNode(2);
	t1->left->left = &TreeNode(5);
	
	TreeNode* t2 = &TreeNode(2);
	t2->left = &TreeNode(1);
	t2->right = &TreeNode(3);
	t2->left->right = &TreeNode(4);
	t2->right->right = &TreeNode(7);

	TreeNode* result = mergeTrees(t1, t2);
	printf("%d\n", result->val);
	printf("%d, %d", result->left->val, result->right->val);

}
