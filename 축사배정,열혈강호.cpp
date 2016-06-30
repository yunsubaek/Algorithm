//https://www.acmicpc.net/problem/2188
//https://www.acmicpc.net/problem/11375
//축사배정-네트워크 플로우(200)
//열혈강호-네트워크 플로우(1000)
#include "bits_stdc++.h"
#define SIZE 1002
using namespace std;
vector<int> v[SIZE];
int ans[SIZE];
//방문점은 계속 새로 초기화,현재 위치를 넣음
bool serch(bool visit[], int now)
{
	if (visit[now])	return 0;
	visit[now] = 1;
	for (int i = 0; i < v[now].size(); i++)
	{
		int k = v[now][i];
		//타고타고 가는거
		if (ans[k] == 0 || serch(visit, ans[k]))
		{
			ans[k] = now;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int si;
		scanf("%d", &si);
		for (int j = 0; j < si; j++)
		{
			int a;
			scanf("%d", &a);
			v[i].push_back(a);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		bool visit[SIZE] = { 0 };
		if (serch(visit, i)) cnt++;
	}
	printf("%d\n", cnt);
}