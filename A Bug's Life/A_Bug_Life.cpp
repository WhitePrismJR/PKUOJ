#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 2001;
bool flag = false;
//父亲节点
int Father[N];
// 要想与根节点之间的关系如何表示？可以用0表示与根节点同性别，
//用1表示与根节点是不同性别，可以用%2，来判断两只虫子的性别
//是不是相同，对2取余可以保证,用r[N]来表示N节点与根节点的关系
int  r[N];
int Find(int x)
{
	if (x == Father[x]) return x;
	int temp = Father[x];
	//如果不是根节点，那么把父节点继续拿去找根节点，然后令x的父节点直接为根节点
	//为路径压缩
	Father[x] = Find(Father[x]);
	//更新x与父节点的关系
	r[x] = (r[x] + r[temp]) % 2;
	return Father[x];
}

void Union(int x, int y)
{
	auto fx = Find(x);
	auto fy = Find(y);
	if (fx == fy)
	{
		//如果2个节点的根节点相同，且性别也相同，那么是homesexual
		if (r[x] == r[y])
		{
			flag = true;
			return;
		}
	}
	else
	{
		//如果不同，把fx合到fy的树里去
		Father[fx] = fy;
		//且改变fx节点与父节点的状态
		r[fx] = (r[x] + r[y] + 1) % 2;
	}
}

int main()
{
	int scenario;
	cin >> scenario;
	int cnt = 1;
	while (scenario-- > 0)
	{
		int n, m;
		cin >> n >> m;
		//每次场景将flag重新重置为false
		flag = false;
		for (int i = 1; i <= n; i++)
		{
			Father[i] = i;
			r[i] = 0;
		}
		vector<std::pair<int, int>> v;
		for (int i = 0; i < m; i++)
		{
			int tempa, tempb;
			cin >> tempa >> tempb;
			v.emplace_back(tempa, tempb);
		}
		for (int i = 0; i < m; i++)
		{
			Union(v[i].first, v[i].second);
		}
		if (flag)
		{
			std::cout << "Scenario #" + to_string(cnt) + ":" << std::endl;
			std::cout << "Suspicious bugs found!" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Scenario #" + to_string(cnt) + ":" << std::endl;
			std::cout << "No suspicious bugs found!" << std::endl;
			std::cout << std::endl;
		}
		cnt++;
	}
	return 0;
}