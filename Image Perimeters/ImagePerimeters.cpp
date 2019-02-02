#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int cnt = 0;
//��ֹ�ظ�����
bool visit[22][22];
bool DFS(char Perimeters[22][22], int clickX, int clickY)
{
	if (!visit[clickX][clickY])
	{
		visit[clickX][clickY] = true;
		if (Perimeters[clickX][clickY] != 'X')
		{
			//cnt++;
			return false;
		}
		else
		{
			//cnt = cnt + 4;
			//����
			DFS(Perimeters, clickX + 1, clickY + 1);
			DFS(Perimeters, clickX + 1, clickY - 1);
			DFS(Perimeters, clickX - 1, clickY + 1);
			DFS(Perimeters, clickX - 1, clickY - 1);

			//����ұ߲����ڣ���ô�ܳ���һ
			if (!DFS(Perimeters, clickX + 1, clickY))
			{
				//std::cout << clickX << ";" << clickY << std::endl;
				cnt++;
			}
			if (!DFS(Perimeters, clickX - 1, clickY))
			{
				//std::cout << clickX << ";" << clickY << std::endl;
				cnt++;
			}
			if (!DFS(Perimeters, clickX, clickY + 1))
			{
				//std::cout << clickX << ";" << clickY << std::endl;
				cnt++;
			}
			if (!DFS(Perimeters, clickX, clickY - 1))
			{
				//std::cout << clickX << ";" << clickY << std::endl;
				cnt++;
			}
			return true;
		}
	}
	else
	{
		//����Ѿ���̽������Ҳ���X������false
		if (Perimeters[clickX][clickY] != 'X')
		{
			//cnt++;
			return false;
		}
		return true;
	}
	
}

int main()
{
	int N, M, clickX, clickY;
	std::vector<int> result;
	while (true)
	{
		cnt = 0;
		char Perimeters[22][22];
		memset(Perimeters, 0, sizeof(Perimeters));
		memset(visit, false, sizeof(visit));
		cin >> N >> M >> clickX >> clickY;
		if (N == 0 || M == 0)
		{
			break;
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> Perimeters[i][j];
			}
		}
		DFS(Perimeters, clickX, clickY);
		result.push_back(cnt);
	}
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
	return 0;
}