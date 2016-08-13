#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		int maxCouple = 0;
		string str_ans = "";
		map<string, bool> tmpans;
		vector<string> ans;
		this->dfs(0, s, str_ans, tmpans, maxCouple);

		for (map<string, bool>::iterator iter = tmpans.begin(); iter != tmpans.end(); ++iter)
		{
			if ((*iter).first.length() >= maxCouple)
			{
				ans.push_back((*iter).first);
			}
		}
		return ans;
    }

    void dfs(int i_Left_morethan_Right, string str_remain_pat, string str_ans, std::map<string, bool>& tmpans, int& maxCouple)
    {
    	if(i_Left_morethan_Right < 0)
    	{
    		return;
    	}
    	if(str_remain_pat.length() == 0 )
    	{
    		if(i_Left_morethan_Right == 0 && str_ans.length() >= maxCouple)
    		{
				tmpans.insert(make_pair(str_ans, true));
				maxCouple = str_ans.length();
    		}
    		return ;
    	}
    	if(str_remain_pat[0] == '(')
    	{    		
    		dfs(i_Left_morethan_Right + 1, str_remain_pat.substr(1), str_ans + str_remain_pat[0], tmpans, maxCouple);
    		dfs(i_Left_morethan_Right, str_remain_pat.substr(1), str_ans, tmpans, maxCouple);
    	}
    	else if(str_remain_pat[0] == ')')
    	{
    		dfs(i_Left_morethan_Right - 1, str_remain_pat.substr(1),  str_ans + str_remain_pat[0], tmpans, maxCouple);
    		dfs(i_Left_morethan_Right, str_remain_pat.substr(1), str_ans, tmpans, maxCouple);
    	}
    	else
    	{
    		dfs(i_Left_morethan_Right, str_remain_pat.substr(1), str_ans + str_remain_pat[0], tmpans, maxCouple);
    	}
    }
};

int main()
{
	Solution sol;
	string str;
	while(cin>>str)
	{
		std::vector<string> ans = sol.removeInvalidParentheses(str);
		for(int i = 0; i<ans.size(); ++i)
		{
			cout<<ans[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
/*
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
")()("
"()())()"
*/