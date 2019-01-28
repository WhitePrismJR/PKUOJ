#include <iostream>
#include <vector>
using namespace std;
int book[202];
int main()
{
	int N, M;
	cin >> N >> M;
	std::vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int tempBook;
		cin >> tempBook;
		v.emplace_back(tempBook);
		book[tempBook]++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (book[v[i]] == 1)
		{
			std::cout << "BeiJu" << std::endl;
		}
		else
		{
			std::cout << book[v[i]]-1 << std::endl;
		}
	}
	return 0;
}