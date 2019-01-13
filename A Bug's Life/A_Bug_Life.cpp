#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 2001;
bool flag = false;
//���׽ڵ�
int Father[N];
// Ҫ������ڵ�֮��Ĺ�ϵ��α�ʾ��������0��ʾ����ڵ�ͬ�Ա�
//��1��ʾ����ڵ��ǲ�ͬ�Ա𣬿�����%2�����ж���ֻ���ӵ��Ա�
//�ǲ�����ͬ����2ȡ����Ա�֤,��r[N]����ʾN�ڵ�����ڵ�Ĺ�ϵ
int  r[N];
int Find(int x)
{
	if (x == Father[x]) return x;
	int temp = Father[x];
	//������Ǹ��ڵ㣬��ô�Ѹ��ڵ������ȥ�Ҹ��ڵ㣬Ȼ����x�ĸ��ڵ�ֱ��Ϊ���ڵ�
	//Ϊ·��ѹ��
	Father[x] = Find(Father[x]);
	//����x�븸�ڵ�Ĺ�ϵ
	r[x] = (r[x] + r[temp]) % 2;
	return Father[x];
}

void Union(int x, int y)
{
	auto fx = Find(x);
	auto fy = Find(y);
	if (fx == fy)
	{
		//���2���ڵ�ĸ��ڵ���ͬ�����Ա�Ҳ��ͬ����ô��homesexual
		if (r[x] == r[y])
		{
			flag = true;
			return;
		}
	}
	else
	{
		//�����ͬ����fx�ϵ�fy������ȥ
		Father[fx] = fy;
		//�Ҹı�fx�ڵ��븸�ڵ��״̬
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
		//ÿ�γ�����flag��������Ϊfalse
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