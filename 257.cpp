#include <iostream>
#include <vector>
#include <string>
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		this->dfs(root, "", ans);
		return ans;
	}
private:
	void dfs(TreeNode* root, string str, vector<string>& ans)
	{
		if (root == NULL)
		{
			return;
		}
		str = str + this->int2str(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			ans.push_back(str);
			return;
		}
		str = str + "->";
		if (root->left != NULL)
		{
			this->dfs(root->left, str, ans);
		}
		if (root->right != NULL)
		{
			this->dfs(root->right, str, ans);
		}
	}
	string int2str(int num)
	{
		string op = "";
		string ans = "";
		if (num == 0)
		{
			return ans = "0";
		}
		if (num < 0)
		{
			op = "-";
			num *= -1;
		}
		while (num)
		{
			ans = char((num % 10) + '0') + ans;
			num /= 10;
		}
		return op + ans;
	}
};

int main()
{
	Solution sol;
	cout << sol.int2str(0) << endl;
	cout << sol.int2str(-2909) << endl;
	cout << sol.int2str(706) << endl;
	system("pause");
	return 0;
}