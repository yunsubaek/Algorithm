//Jennifer Soft - D
#include "bits_stdc++.h"
#define SIZE 12
using namespace std;
//방향을 체크하기 위한 방향 배열
int idx[4] = { 0,0,1,-1 }, idy[4] = { 1,-1,0,0 };

//현재 위치,가중치를 담는 구조체
struct Now
{
	int x, y, cnt;
};

int main()
{
	//n = 맵크기, temp = 가중치 저장 배열.
	int n, temp[SIZE][SIZE] = { 0 };
	//맵 정보
	char arr[SIZE][SIZE] = { 0 };
	scanf("%d", &n);
	//입력
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//저장배열 값을 큰 값으로 초기화
	memset(temp, 0x3f, sizeof temp);
	//bfs
	queue <Now> q;
	//큐에 시작점을 넣고 이동
	q.push({ n - 1,0,arr[n - 1][0] - '0' });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		//현재 가중치가 저장된 값보다 적을 경우에만 탐색
		if (cnt < temp[x][y])
		{
			temp[x][y] = cnt;
			//현재 위치 기준 4방향 탐색
			for (int i = 0; i < 4; i++)
			{
				int xx = x + idx[i], yy = y + idy[i];
				//맵의 범위 안에 있을 경우 가중치를 더한 값을 큐에 넣음
				if (xx >= 0 && yy >= 0 && xx < n && yy < n)
					q.push({ xx,yy,cnt + arr[xx][yy] - '0' });
			}
		}
	}
	//100 이상인 값이 나올 경우 100출력, 아닐경우 원래 값 출력
	printf("%d\n", temp[0][n - 1] >= 100 ? 100 : temp[0][n - 1]);
	return 0;
}