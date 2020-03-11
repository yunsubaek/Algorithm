#include <bits/stdc++.h>
using namespace std;
template <typename T>
class _vector {
public:
	int capacity, _size;
	T *arr;
	_vector() {
		capacity = 4;
		_size = 0;
		arr = new T[capacity];
	}
	void resize(int n) {
		T *temp = new T[n];
		for (int i = 0; i<_size; i++)
			temp[i] = arr[i];
		delete arr;
		arr = temp;
	}
	void push_back(T data) {
		if (_size == capacity) {
			capacity *= 2;
			resize(capacity);
		}
		arr[_size++] = data;
	}
	int size() {
		return _size;
	}
	T* begin() {
		return &arr[0];
	}
	T* end() {
		return &arr[0] + _size;
	}
	void clear() {
		capacity = 4;
		_size = 0;
		delete arr;
		arr = new T[4];
	}
	T operator [](int idx) {
		return arr[idx];
	}
};
int V, E;
_vector<pair<int, int>> adj[20001];
int dist[20001];
const int INF = 0x3f3f3f3f;
int st;
int main() {
	scanf("%d%d%d", &V, &E, &st);
	for (int i = 0; i<E; i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({ b, d });
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost>dist[now])
			continue;
		for (int i = 0; i<adj[now].size(); i++) {
			int there = adj[now][i].first;
			int there_cost = adj[now][i].second + cost;
			if (there_cost<dist[there]) {
				dist[there] = there_cost;
				pq.push({ -there_cost, there });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}
