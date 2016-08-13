#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		return bfs(root);
    }

    string bfs(TreeNode* root)
    {
		string ans = "";
		if (root == NULL)
		{
			return ans;
		}

		queue<TreeNode*> Q;
		Q.push(root);
		ans = ans + int2str(root->val);
		while (!Q.empty())
		{
			TreeNode* p = Q.front(); Q.pop();
			TreeNode* left = p->left;
			TreeNode* right = p->right;
			
			if (left == NULL)
			{
				ans = ans + ",null";
			}
			else
			{
				ans = ans + "," + int2str(left->val);
				Q.push(left);
			}

			if (right != NULL)
			{
				ans = ans + "," + int2str(right->val);
				Q.push(right);
			}
		}
		return ans;
    }

    string int2str(int num)
    {
    	string ans = "";
    	while(num)
    	{
    		ans = char(num%10 + '0') + ans;
    		num /= 10;
    	}
    	if(ans == "")
    	{
    		ans = "0";
    	}
    	return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return re_bfs(data);
    }

    TreeNode* re_bfs(string data)
    {
    	TreeNode* root = NULL;
    	if(data == "" || data == "null")
    	{
    		return root;
    	}

    	std::vector<string> strnums = split(data, ",");
    	queue<TreeNode*> Q;
    	
    	int curCount = 0;
    	root = new TreeNode(str2int(strnums[curCount ++]));  
    	Q.push(root);
    	while(!Q.empty() && curCount < strnums.size())
    	{
    		TreeNode* p = Q.front(); Q.pop();
    		string strNum1 = strnums[curCount ++];
    		string strNum2 = strnums[curCount ++];

    		if(strNum1 != "null")
    		{
    			TreeNode* tmp = new TreeNode(str2int(strNum1));
    			p->left = tmp;
    			Q.push(tmp);
    		}
    		if(strNum2 != "null")
    		{
    			TreeNode* tmp = new TreeNode(str2int(strNum2));
    			p->right = tmp;
    			Q.push(tmp);
    		}
    	}
    	return root;
    }

    std::vector<string> split(string data, string sep)
    {
    	std::vector<string> ans;
    	std::size_t find = data.find(sep);
    	while(find != std::string::npos)
    	{
    		ans.push_back(data.substr(0, find));
    		data = data.substr(find+1);
    		find = data.find(sep);
    	}
    	ans.push_back(data);
    	return ans;
    }

    int str2int(string data)
    {
    	int ans = 0;
    	int i = 0;
    	while(i < data.length())
    	{
    		ans = ans*10 + int(data[i] - '0');
    		++i;
    	}
    	return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{

	Codec sol;
	string data;
	while(cin>>data)
	{
		TreeNode* root = sol.deserialize(data);
		cout<<sol.serialize(root)<<endl;
	}
	return 0;
}

/*
"[1,2,3,null,null,4,5]"
"[1,2,3,null,77,4,5]"
*/