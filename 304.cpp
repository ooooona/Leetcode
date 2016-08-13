#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		this->initial(nums);

		for (int i = 0; i < nums.size(); ++i)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	int sumRange(int i, int j) {
		return this->ans[j + 1] - this->ans[i];
	}
	void initial(const vector<int> &nums)
	{
		this->ans.resize(nums.size() + 1, 0);
		for (int i = 1; i < nums.size() + 1; ++i)
		{
			this->ans[i] = nums[i - 1] + this->ans[i - 1];
		}
	}

private:
	vector<int> ans;
};

int main()
{
	vector< int > array;
	int data[6] = { -2, 0, 3, -5, 2, -1	};
	for (int i = 0; i < 6; ++i)
	{
		array.push_back(data[i]);
	}
	NumArray sol(array);
	cout << sol.sumRange(0,2) << endl;
	cout << sol.sumRange(2,5) << endl;
	cout << sol.sumRange(0,5) << endl;
	system("pause");
	return 0;
}
/*
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/