#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
* Definition for a point.
*/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		map<double, int> kHash;
		int duplicate = 0;
		int ansMax = 0;
		for (int i = 0; i < points.size(); ++i)
		{
			kHash.clear();
			duplicate = 1;
			int tmpMax = 0;
			for (int j = 0; j < points.size(); ++j)
			{
				if (j == i) continue;
				if (isSame(points[i], points[j]))
				{
					duplicate++;
					continue;
				}
				double K = (points[i].y == points[j].y) ? INT_MAX : (double(points[i].x - points[j].x) / double(points[i].y - points[j].y));
				if (kHash.find(K) == kHash.end())
				{
					kHash.insert(make_pair(K, 0));
				}
				kHash[K]++;
				tmpMax = tmpMax >= kHash[K] ? tmpMax : kHash[K];
			}
			ansMax = ansMax >= (duplicate + tmpMax) ? ansMax : (duplicate + tmpMax);
		}
		return ansMax;
	}
private:
	bool isSame(Point& p1, Point& p2)
	{
		return ((p1.x == p2.x) && (p1.y == p2.y));
	}
};

int main()
{
	Solution sol;
	Point p1(-4, 1), p2(-7, 7), p3(-1, 5), p4(9, -25);
	vector<Point> points;
	points.push_back(p1), points.push_back(p2), points.push_back(p3), points.push_back(p4);
	cout << sol.maxPoints(points) << endl;
	system("pause");
	return 0;
}

/*
[[-4,1],[-7,7],[-1,5],[9,-25]]
*/