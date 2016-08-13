#include <iostream>
#include <vector>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return this->buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

private:
	TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight)
	{
		if (preLeft > preRight)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[preLeft]);
		///inorder;
		int inPartion = inLeft;
		while (inorder[inPartion] != preorder[preLeft])
			++inPartion;

		root->left = this->buildTree(preorder, preLeft + 1, (inPartion - inLeft + preLeft), inorder, inLeft, inPartion - 1);
		root->right = this->buildTree(preorder, (preRight - inRight + inPartion + 1), preRight, inorder, inPartion + 1, inRight);
		return root;
	}	
};

int main()
{
	return 0;
}