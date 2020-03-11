#include"bits_stdc++.h"
#define SIZE 502
using namespace std;

int v_cost[SIZE], v_cnt[SIZE],total[SIZE];
vector<int> v[SIZE];
queue<int> q;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &v_cost[i]);
		while (1) {
			int a;
			scanf("%d", &a);
			if (a == -1)break;
			v[a].push_back(i);
			v_cnt[i]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v_cnt[i]) {
			q.push(i);
			total[i] = v_cost[i];
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			total[y] = max(total[y], total[x] + v_cost[y]);
			v_cnt[y]--;
			if (!v_cnt[y])q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", total[i]);
	}
}