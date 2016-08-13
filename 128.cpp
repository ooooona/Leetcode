#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		return 0;
		unordered_set<int> hashTable;
		for (int i = 0; i < nums.size(); ++i)
		{
			hashTable.insert(nums[i]);
		}
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (hashTable.find(nums[i]) == hashTable.end())
			{
				continue;
			}
			int tmpAns = 0;
			int curNum = nums[i];
			while (hashTable.find(curNum) != hashTable.end())
			{
				hashTable.erase(curNum);
				--curNum;
				++tmpAns;
			}
			curNum = nums[i] + 1;
			while (hashTable.find(curNum) != hashTable.end())
			{
				hashTable.erase(curNum);
				++curNum;
				++tmpAns;
			}
			ans = ans > tmpAns ? ans : tmpAns;
		}
		return ans;
	}
};

int main()
{
	return 0;
}