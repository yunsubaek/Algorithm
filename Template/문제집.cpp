//https://www.acmicpc.net/problem/1766
//문제접(우선순위큐 위상정렬)
#include "bits_stdc++.h"
using namespace std;
vector<int> v[32002];
int v_cnt[32002];
priority_queue<int> pq;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v_cnt[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!v_cnt[i]) pq.push(-i);
	}

	while (!pq.empty()) {
		int x = -pq.top();
		pq.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++)
		{
			v_cnt[v[x][i]]--;
			if (v_cnt[v[x][i]] == 0) pq.push(-v[x][i]);
		}
	}
	return 0;
}