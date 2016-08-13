#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        map<char, int> digitals;
		vector<bool> visited;
		visited.resize(guess.length(), false);
        for(int i = 0; i<secret.length(); ++i)
        {
        	map<char, int>::iterator iter = digitals.find(secret[i]);
        	if(iter == digitals.end())
        	{
        		digitals.insert(make_pair(secret[i], 1));
        	}
        	else
        	{
        		digitals[secret[i]] ++;
        	}
        }

        for(int i = 0; i<guess.length(); ++i)
        {
        	if(secret[i] == guess[i])
        	{
        		bulls ++;
        		digitals[guess[i]] --;
				visited[i] = true;
        	}
        }
		for (int i = 0; i < guess.length(); ++i)
		{
			if (visited[i] == true) continue;
			map<char, int>::iterator iter = digitals.find(guess[i]);
			if (iter != digitals.end())
			{
				if (digitals[guess[i]] > 0)
				{
					cows++;
					digitals[guess[i]] --;
				}
			}
		}
        return int2str(bulls) + "A" + int2str(cows) + "B";
    }

    string int2str(int num)
    {
    	string ans = "";
    	while(num)
    	{
    		ans = char(num%10 + '0') + ans;
    		num /= 10;
    	}
		if (ans == "")
		{
			ans = "0";
		}
    	return ans;
    }
};

int main()
{
	Solution sol;
	string secret, guess;
	while(cin>>secret >> guess)
	{
		cout<<sol.getHint(secret, guess)<<endl;
	}

	return 0;
}

/*
Secret number:  "1807"
Friend's guess: "7810"

Secret number:  "1123"
Friend's guess: "0111"

"1122"
"1222"
*/