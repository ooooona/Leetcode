#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int N = citations.size();
		int low = 0; 
		int high = N;
		int h = 0;
		while (low < high)
		{
			int mid = low + ((high - low) >> 1);
			if (citations[mid] >(N - mid))
			{
				h = this->max(h, (N - mid));
				high = mid;
			}
			else
			{
				h = this->max(h, citations[mid]);
				low = mid + 1;
			}
		}
		return h;
	}
private:
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	Solution sol;
	vector<int> data;
	data.push_back(0);
	cout << sol.hIndex(data) << endl;
	system("pause");
	return 0;
}