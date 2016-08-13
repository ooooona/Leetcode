#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		int n = nums1.size();
		int m = nums2.size();
		if ((n + m) % 2)
		{
			//cout << ((m + n) >> 1) << " : " << this->findKthNum(nums1, nums2, ((n + m) >> 1)) << endl;
			return this->findKthNum(nums1, nums2, (n + m) >> 1);
		}
		else
		{
			//cout << ((m + n) / 2) << " : ";
			//cout << this->findKthNum(nums1, nums2, ((n + m) / 2)) << endl;
			//cout << ((m + n) / 2) - 1 << " : " << this->findKthNum(nums1, nums2, ((n + m) / 2) - 1) << endl;
			return (this->findKthNum(nums1, nums2, (n + m >> 1)) + this->findKthNum(nums1, nums2, ((n + m) >> 1) - 1)) / 2.0;
		}
	}

private:
	int findKthNum(vector<int>& nums1, vector<int>& nums2, int k)
	{
		//cout << "\nfind " << k << endl;
		//cout << nums1.size() << " : " << endl;
		//for (int i = 0; i < nums1.size(); ++i)
		//{
		//	cout << nums1[i] << " ";
		//}
		//cout << endl;
		//cout << nums2.size() << " : " << endl;
		//for (int i = 0; i < nums2.size(); ++i)
		//{
		//	cout << nums2[i] << " ";
		//}
		//cout << endl;
		if (nums1.size() == 0)
		{
			return nums2[k];
		}
		if (nums2.size() == 0)
		{
			return nums1[k];
		}
		if (k == 0)
		{
			return this->min(nums1[0], nums2[0]);
		}
		if (nums1.size() > nums2.size())
		{
			return this->findKthNum(nums2, nums1, k);
		}
		int mid1 = this->min(nums1.size() - 1, (k >> 1));
		int mid2 = k - mid1 - 1;
		if (nums1[mid1] > nums2[mid2])
		{
			vector<int> tmp1;
			for (int i = 0; i <= mid1; ++i)
			{
				tmp1.push_back(nums1[i]);
			}
			vector<int> tmp2;
			for (int i = mid2 + 1; i < nums2.size(); ++i)
			{
				tmp2.push_back(nums2[i]);
			}
			return this->findKthNum(tmp1, tmp2, k - mid2 - 1);
		}
		else if (nums1[mid1] < nums2[mid2])
		{
			vector<int> tmp1;
			for (int i = mid1 + 1; i < nums1.size(); ++i)
			{
				tmp1.push_back(nums1[i]);
			}
			vector<int> tmp2;
			for (int i = 0; i <= mid2; ++i)
			{
				tmp2.push_back(nums2[i]);
			}
			return this->findKthNum(tmp1, tmp2, k - mid1 - 1);
		}
		else
		{
			return nums1[mid1];
		}
	}

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
	vector<int> nums1, nums2;
	nums1.push_back(1), nums1.push_back(2);
	nums2.push_back(1), nums2.push_back(1);

	Solution sol;
	cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

	system("pause");
	return 0;
}