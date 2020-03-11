//https://www.acmicpc.net/problem/1922
//네트워크 연결(최소 스패닝 트리 - 프림)
#include "bits_stdc++.h"
#define SIZE 1002
#define INF 1000000000
using namespace std;
//도착지, 가중치
vector<pair<int, int> > v[SIZE];
//가중치, 도착지
priority_queue<pair<int, int> > pq;
bool visit[SIZE];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}
	int result = 0;
	//시작점 설정
	pq.push(make_pair(-INF, 1));
	while (!pq.empty()) {
		int x = pq.top().second;
		if (visit[x]) {
			pq.pop();
			continue;
		}
		visit[x] = 1;
		if (pq.top().first != -INF)result += -pq.top().first;
		pq.pop();
		int len = v[x].size();
		for (int i = 0; i < len; i++) {
			if (!visit[v[x][i].first]) {
				pq.push(make_pair(-v[x][i].second, v[x][i].first));
			}
		}
	}
	printf("%d\n", result);
}