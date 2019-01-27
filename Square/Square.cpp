//http://bailian.openjudge.cn/practice/2002/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(int tempX, int tempY) :x(tempX), y(tempY)
	{

	}
};
bool operator < (Point q, Point w)
{
	if (q.x != w.x) return q.x > w.x;
	else return q.y > w.y;
}
bool operator == (Point q, Point w)
{
	if (q.x == w.x&& q.y == w.y) return true;
	return false;
}

int main()
{
	int n;
	std::vector<int> t;
	while (1)
	{
		scanf("%d", &n);
		int cnt = 0;
		if (n == 0)
		{
			break;
		}
		std::set<Point> v;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			//Point tempPoint(x, y);
			v.emplace(x, y);
		}
		for (auto itI = v.begin(); itI != v.end(); itI++)
		{
			auto itJ = itI;
			itJ++;
			for (; itJ != v.end(); itJ++)
			{

				Point vRightTop((*itI).x + (-(*itJ).y + (*itI).y), (*itI).y + ((*itJ).x - (*itI).x));
				Point vRightBottom((*itJ).x + (-(*itJ).y + (*itI).y), (*itJ).y + ((*itJ).x - (*itI).x));

				Point vLeftTop((*itI).x - (-(*itJ).y + (*itI).y), (*itI).y - ((*itJ).x - (*itI).x));
				Point vLeftBottom((*itJ).x - (-(*itJ).y + (*itI).y), (*itJ).y - ((*itJ).x - (*itI).x));

				//auto findRightTopResult = std::find(v.begin(), v.end(), vRightTop);
				//auto findRightBottomResult = std::find(v.begin(), v.end(), vRightBottom);
				/*auto findRightTopResult = v.find(vRightTop);
				auto findRightBottomResult = v.find(vRightBottom);*/

				//¶¼ÕÒµ½ÁË
				if (v.count(vRightTop)==1 && v.count(vRightBottom) == 1)
				{
					cnt++;
				}
				//auto findLeftTopResult = std::find(v.begin(), v.end(), vLeftTop);
				//auto findLeftBottomResult = std::find(v.begin(), v.end(), vLeftBottom);
				/*auto findLeftTopResult = v.find(vLeftTop);
				auto findLeftBottomResult = v.find(vLeftBottom);*/

				if (v.count(vLeftTop) == 1 && v.count(vLeftBottom) == 1)
				{
					cnt++;
				}
			}
		}
		t.push_back(cnt / 4);
	}
	for (int i = 0; i < t.size(); i++)
	{
		std::cout << t[i] << std::endl;
	}
	return 0;
}