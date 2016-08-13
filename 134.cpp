#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int maxVal = -1;
		for (int i = 0; i < gas.size(); ++i)
		{
			maxVal = maxVal > (gas[i] - cost[i]) ? maxVal : (gas[i] - cost[i]);
		}
		if (maxVal < 0)
		{
			return -1;
		}
		
		for (int i = 0; i < gas.size(); ++i)
		{
			if (maxVal == (gas[i] - cost[i]))
			{
				if (this->isCompleteCircle(gas, cost, i))
				{
					return i;
				}
			}
		}
		return -1;
	}
private:
	bool isCompleteCircle(vector<int>& gas, vector<int>& cost, int startIndex)
	{
		int sum = gas[startIndex] - cost[startIndex];
		int cnt = (startIndex + 1) % gas.size();
		while (cnt != startIndex)
		{
			sum += gas[cnt] - cost[cnt];
			if (sum < 0)
			{
				return false;
			}
			cnt = (cnt + 1) % gas.size();
		}
		return true;
	}
};

int main()
{
	vector<int> gas, cost;
	gas.push_back(2), cost.push_back(2);
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	system("pause");
	return 0;
}