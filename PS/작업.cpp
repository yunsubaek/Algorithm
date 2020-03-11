//https://www.acmicpc.net/problem/2056
//�۾�(��������) - ��� ���� �湮�ϰ� ������ ��찡 ������ ������ �ƴҼ��� ������ üũ
#include "bits_stdc++.h"
using namespace std;
//������
vector<int> v[10002];
//������
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
			//b = �����, i = ������
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