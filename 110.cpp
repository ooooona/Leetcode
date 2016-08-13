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
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}
		this->flag = true;
		this->getDeltaHeight(root);
		return this->flag;
	}
private:
	int getDeltaHeight(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int leftHeight = this->getDeltaHeight(root->left);
		int rightHeight = this->getDeltaHeight(root->right);
		if (this->abs(leftHeight - rightHeight) > 1)
		{
			flag = false;
		}
		return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	int abs(int a)
	{
		return a >= 0 ? a : -1 * a;
	}
	bool flag;
};

int main()
{
	return 0;
}