//Jennifer Soft - D
#include "bits_stdc++.h"
#define SIZE 12
using namespace std;
//������ üũ�ϱ� ���� ���� �迭
int idx[4] = { 0,0,1,-1 }, idy[4] = { 1,-1,0,0 };

//���� ��ġ,����ġ�� ��� ����ü
struct Now
{
	int x, y, cnt;
};

int main()
{
	//n = ��ũ��, temp = ����ġ ���� �迭.
	int n, temp[SIZE][SIZE] = { 0 };
	//�� ����
	char arr[SIZE][SIZE] = { 0 };
	scanf("%d", &n);
	//�Է�
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//����迭 ���� ū ������ �ʱ�ȭ
	memset(temp, 0x3f, sizeof temp);
	//bfs
	queue <Now> q;
	//ť�� �������� �ְ� �̵�
	q.push({ n - 1,0,arr[n - 1][0] - '0' });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		//���� ����ġ�� ����� ������ ���� ��쿡�� Ž��
		if (cnt < temp[x][y])
		{
			temp[x][y] = cnt;
			//���� ��ġ ���� 4���� Ž��
			for (int i = 0; i < 4; i++)
			{
				int xx = x + idx[i], yy = y + idy[i];
				//���� ���� �ȿ� ���� ��� ����ġ�� ���� ���� ť�� ����
				if (xx >= 0 && yy >= 0 && xx < n && yy < n)
					q.push({ xx,yy,cnt + arr[xx][yy] - '0' });
			}
		}
	}
	//100 �̻��� ���� ���� ��� 100���, �ƴҰ�� ���� �� ���
	printf("%d\n", temp[0][n - 1] >= 100 ? 100 : temp[0][n - 1]);
	return 0;
}