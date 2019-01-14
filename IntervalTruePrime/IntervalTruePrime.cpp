#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}


int Reverse(int n)
{
	std::string temp;
	std::stringstream ss;
	ss << n;
	ss >> temp;
	reverse(temp.begin(), temp.end());
	int t = atoi(temp.c_str());
	return t;
}

int main()
{
	int M, N;
	cin >> M >> N;
	std::string c;
	for (int i = M; i <= N; i++)
	{
		if (isPrime(i) && isPrime(Reverse(i)))
		{
			stringstream ss;
			string temp;
			ss << i;
			ss >> temp;
			c=c+temp+",";
		}
	}
	if (c.size()<1)
	{
		std::cout << "No";
	}
	else
	{
		for (int i = 0; i < c.size()-1;i++)
		{
			std::cout << c[i];
		}
	}
	//system("pause");
	return 0;
}