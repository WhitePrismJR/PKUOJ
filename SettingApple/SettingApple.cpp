#include <iostream>
#include <vector>
using namespace std;
//dp[i][j]����i��ƻ������j��������ķŷ��ж�����
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
			//i=2,j=2��ʼ���鷳��Ҫ�м���
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
					//��Ϊ��0��������0��������0Ϊ����һ�������ӣ�Ϊdp[i][j - 1]����0��ô
					//�൱��ÿ������������һ��ƻ�����൱��ÿ�����Ӷ���һ������j����û�����ˣ���ֻʣ��i-j(����)��ȥ����
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