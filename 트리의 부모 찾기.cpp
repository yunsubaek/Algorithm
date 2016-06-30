//https://www.acmicpc.net/problem/11725
//트리의 부모 찾기
#include "bits_stdc++.h"
#define SIZE 100002
using namespace std;
int par[SIZE], n;
vector<int> v[SIZE];

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int>q;
	q.push(1);
	par[1] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (par[v[x][i]] == 0) {
				par[v[x][i]] = x;
				q.push(v[x][i]);
			}
		}
	}

	for (int i = 2; i <= n; i++){
		printf("%d\n", par[i]);
	}
}