#include <iostream>
#include <vector>
using namespace std;
std::vector<std::pair<int, int>>v;
//dp[i]��ʾ��1������i���ж��ٿ��ܵ�·��
long long dp[53];
int main()
{
	int n;
	cin >> n;
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		int tempa, tempb;
		cin >> tempa >> tempb;
		if (tempb - tempa + 1 > max)
		{
			max = tempb - tempa + 1;
		}
		v.emplace_back(tempa, tempb);
	}
	dp[2] = 1; dp[3] = 2;
	for (int i = 0; i < max + 1; i++)
	{
		dp[i + 4] = dp[i + 2] + dp[i + 3];
	}
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << dp[v[i].second - v[i].first + 1] << std::endl;
	}
	return 0;
}