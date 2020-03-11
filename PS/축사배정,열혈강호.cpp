//https://www.acmicpc.net/problem/2188
//https://www.acmicpc.net/problem/11375
//������-��Ʈ��ũ �÷ο�(200)
//������ȣ-��Ʈ��ũ �÷ο�(1000)
#include "bits_stdc++.h"
#define SIZE 1002
using namespace std;
vector<int> v[SIZE];
int ans[SIZE];
//�湮���� ��� ���� �ʱ�ȭ,���� ��ġ�� ����
bool serch(bool visit[], int now)
{
	if (visit[now])	return 0;
	visit[now] = 1;
	for (int i = 0; i < v[now].size(); i++)
	{
		int k = v[now][i];
		//Ÿ��Ÿ�� ���°�
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