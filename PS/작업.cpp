//https://www.acmicpc.net/problem/2056
//작업(위상정렬) - 모든 점을 방문하고 끝나는 경우가 마지막 정점이 아닐수도 있음을 체크
#include "bits_stdc++.h"
using namespace std;
//도착지
vector<int> v[10002];
//도착지
queue<int> pq;
int total[10002], v_cnt[10002], v_cost[10002];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d %d", &v_cost[i], &a);
		for (int j = 0; j < a; j++) {
			int b;
			scanf("%d", &b);
			//b = 출발지, i = 도착지
			v[b].push_back(i);
			v_cnt[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!v_cnt[i]) {
			pq.push(i);
			total[i] = v_cost[i];
		}
	}

	while (!pq.empty()) {
		int x = pq.front();
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			v_cnt[y]--;
			total[y] = max(total[y], total[x] + v_cost[y]);
			if (v_cnt[v[x][i]] == 0) {
				pq.push(v[x][i]);
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= n; i++)
		if (result < total[i])result = total[i];
	printf("%d\n", result);
	return 0;
}