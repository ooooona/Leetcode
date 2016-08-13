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
	int maxPathSum(TreeNode* root) {
		int ans = -999999;
		this->findMaxPathSum(root, ans);
		return ans;
	}
private:
	int findMaxPathSum(TreeNode* root, int& max)
	{
		if (root == NULL)
		{
			return 0;
		}
		int leftVal = this->findMaxPathSum(root->left, max);
		int rightVal = this->findMaxPathSum(root->right, max);
		int tmp = this->MAX2(this->MAX2(leftVal+root->val, rightVal+root->val), this->MAX2(leftVal + rightVal + root->val, root->val));
		max = this->MAX2(tmp, max);

		return this->MAX2(leftVal, rightVal) + root->val > 0 ? this->MAX2(leftVal, rightVal) + root->val : 0;
	}
	int MAX2(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	return 0;
}