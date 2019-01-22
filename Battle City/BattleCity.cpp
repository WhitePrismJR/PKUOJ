//http://poj.org/problem?id=2312
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<string>
#include <queue>
using namespace std;
struct Node
{
	int x, y;
	//cnt��ʾ���յ�Ĳ���
	int cnt;
	Node(int _x, int _y, int _cnt)
	{
		x = _x;
		y = _y;
		cnt = _cnt;
	}
};
//�����£��ң��ϣ��ĸ�����
int directionX[] = { -1,0,1,0 };
int directionY[] = { 0,1,0,-1 };

//�洢���е��ַ�
std::vector<std::vector<char>>vChar;

//���仯��������
std::vector<std::vector<int>> vInt;
std::vector<string> vString;
Node startPoint(0, 0, 0);
Node finalPoint(0, 0, 0);
const int INF = 0x3f3f3f;



void bfs(int M, int N)
{
	int ans = INF;
	queue<Node> q;
	q.push(startPoint);
	while (!q.empty())
	{
		Node temp = q.front();
		q.pop();
		//�ҵ����յ��ˣ�������ʱ��ĵ��յ��ֵ
		if (temp.x == finalPoint.x&&temp.y == finalPoint.y&&temp.cnt < ans)
		{
			ans = temp.cnt;
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int tempNextX = temp.x + directionX[i];
			int tempNextY = temp.y + directionY[i];
			int tempNextCnt = temp.cnt + 1;
			if (tempNextX < 0 || tempNextY < 0 || tempNextX >= M || tempNextY >= N)
			{
				continue;
			}
			if (vChar[tempNextX][tempNextY] == 'S' || vChar[tempNextX][tempNextY] == 'R')
			{
				continue;
			}
			if (vChar[tempNextX][tempNextY] == 'B')
			{
				tempNextCnt++;
			}
			//����Ѿ���·���ܵ��ﵱǰ�ڵ㣬�ұȵ�ǰ·�����ѵĴ���С����ôֱ���������·��
			if (vInt[tempNextX][tempNextY] <= tempNextCnt)
			{
				continue;
			}
			vInt[tempNextX][tempNextY] = tempNextCnt;
			q.push(Node(tempNextX, tempNextY, tempNextCnt));
		}
	}
	if (ans==INF)
	{
		std::cout << "-1" << std::endl;
	}
	else
	{
		std::cout << ans << std::endl;
	}
}
int main()
{
	

	int M, N;
	while (scanf("%d%d", &M, &N) != EOF) 
	{
		vChar.resize(300);
		vInt.resize(300);
		for (int i = 0; i < vChar.size(); i++)
		{
			vChar[i].resize(300);
			vInt[i].resize(300);
		}
		for (int i = 0; i < vInt.size(); i++)
		{
			for (int j = 0; j < vInt[0].size(); j++)
			{
				vInt[i][j] = 0x3f3f3f;
			}
		}
		if (M == 0 && N == 0) break;
		for (int i = 0; i < M; i++)
		{
			std::string tempString;
			cin >> tempString;
			vString.push_back(tempString);
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				vChar[i][j] = vString[i][j];
				//���
				if (vChar[i][j] == 'Y')
				{
					startPoint.x = i;
					startPoint.y = j;
				}
				else if (vChar[i][j] == 'T')
				{
					finalPoint.x = i;
					finalPoint.y = j;
				}
			}
		}
		bfs(M, N);
		vChar.clear();
		vString.clear();
		vInt.clear();
	}
	return 0;
}