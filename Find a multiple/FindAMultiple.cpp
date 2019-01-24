//http://poj.org/problem?id=2356
#include<iostream>
#include <string.h>

using namespace std;
int num[10001], mod[10001], sum[10001];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	memset(mod, -1, sizeof(mod));
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			sum[i] = num[i];
		}
		else
		{
			sum[i] = num[i] + sum[i - 1];
		}
		if (sum[i] % N == 0)
		{
			std::cout << i + 1 << std::endl;
			for (int j = 0; j <= i; j++)
			{
				std::cout << num[j] << std::endl;
			}
			break;
		}
		//如果有2个余数相同，那么j+1到i就是N的倍数
		else if (mod[sum[i] % N] != -1)
		{
			int j = mod[sum[i] % N];
			std::cout << i - j << std::endl;
			j++;
			for (; j <= i; j++)
			{
				std::cout << num[j] << std::endl;
			}
			break;
		}
		mod[sum[i] % N] = i;
	}
	return 0;
}