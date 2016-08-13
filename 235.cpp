#include <iostream>
using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
		{
			return root;
		}

		int rValue = root->val;
		int pValue = p->val;
		int qValue = q->val;
		if (rValue < pValue && rValue < qValue)
		{
			return this->lowestCommonAncestor(root->right, p, q);
		}
		else if (rValue > pValue && rValue > qValue)
		{
			return this->lowestCommonAncestor(root->left, p, q);
		}
		else
		{
			return root;
		}
	}
};

int main()
{
	system("pause");
	return 0;
}