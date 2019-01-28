#include <iostream>
#include <vector>
using namespace std;
//dp[i][j]代表i个苹果放在j个盘子里的放法有多少种
int dp[21][21];
int main()
{
	int t;
	cin >> t;
	std::vector<int> result;
	for (int i = 0; i < t; i++)
	{
		int M, N;
		cin >> M >> N;
		for (int i = 0; i <= M + 1; i++) {
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		for (int i = 0; i <= N + 1; i++) {
			dp[0][i] = 1;
			//i=2,j=2开始很麻烦，要有记性
			dp[1][i] = 1;
		}

		for (int i = 2; i <= M; i++)
		{
			for (int j = 2; j <= N; j++)
			{
				if (i < j)
				{
					dp[i][j] = dp[i][i];
				}
				else
				{
					//分为有0方案和无0方案，有0为至少一个空盘子，为dp[i][j - 1]，无0那么
					//相当于每个盘子至少有一个苹果，相当于每个盘子都有一个，这j个就没意义了，故只剩下i-j(盘子)个去分配
					dp[i][j] = dp[i][j - 1] + dp[i - j][j];
				}
			}
		}
		result.push_back(dp[M][N]);
	}
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
	return 0;
}