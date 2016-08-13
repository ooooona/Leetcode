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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return this->buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
private:
	TreeNode* buildTree(
		vector<int>& inorder, int inHead, int inTail, vector<int>& postorder, int postHead, int postTail)
	{
		if (inHead > inTail)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder[postTail]);
		///inorder
		int inPartion = inHead;
		while (postorder[postTail] != inorder[inPartion])
			++inPartion;
		root->left = this->buildTree(inorder, inHead, inPartion - 1, postorder, postHead, postHead + inPartion - inHead - 1);
		root->right = this->buildTree(inorder, inPartion + 1, inTail, postorder, postTail + inPartion - inTail, postTail - 1);

		return root;
	}
};

int main()
{
	return 0;
}