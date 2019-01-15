#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.emplace_back(temp);
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				cnt++;
			}
		}
	}
	std::cout << cnt;
	return 0;
}