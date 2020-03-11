////https://www.acmicpc.net/problem/1197
////�ּ� ���д� Ʈ��(����1)
//#include "bits_stdc++.h"
//#define SIZE 10002
//#define INF 1000000000
//using namespace std;
//bool visit[SIZE];
////����ġ, ������
//priority_queue<pair<int, int> > pq;
//vector<pair<int, int> > v[SIZE];
//int main()
//{
//	int v_num, e_num;
//	cin >> v_num >> e_num;
//	for (int i = 0; i < e_num; i++)
//	{
//		int a, b, c;
//		scanf("%d %d %d", &a, &b, &c);
//		v[a].push_back(make_pair(b, c));
//		v[b].push_back(make_pair(a, c));
//	}
//	int result = 0;
//	pq.push(make_pair(-INF, 1));
//	while (!pq.empty())
//	{
//		int x = pq.top().second;
//		if (visit[x]) { 
//			pq.pop();
//			continue; 
//		}
//		visit[x] = 1;
//		if (pq.top().first != -INF)result += -pq.top().first;
//		for (int i = 0; i < v[x].size(); i++) {
//			pq.push(make_pair(-v[x][i].second, v[x][i].first));
//		}
//	}
//	printf("%d\n", result);
//	return 0;
//}

////https://www.acmicpc.net/problem/1197
////�ּ� ���д� Ʈ��(����2)
//#include "bits_stdc++.h"
//#define SIZE 10002
//#define INF 1000000000
//using namespace std;
//bool visit[SIZE];
//vector<pair<int, int> > v[SIZE];
//
//int chk(int idx)
//{
//	int sum = 0;
//	//����ġ, ������
//	priority_queue<pair<int,int> > pq;
//	pq.push(make_pair(-INF, idx));
//	while (!pq.empty())
//	{
//		int x = pq.top().second;
//		if (visit[x])
//		{
//			pq.pop();
//			continue;
//		}
//		visit[x] = 1;
//		if (pq.top().first != -INF) {
//			sum += -pq.top().first;
//		}
//		pq.pop();
//		int len = v[x].size();
//		for (int i = 0; i < len; i++)
//		{
//			if (!visit[v[x][i].first]) {
//				pq.push(make_pair(-v[x][i].second, v[x][i].first));
//			}
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int v_num, e_num;
//	cin >> v_num >> e_num;
//	//�ʱ�ȭ
//	for (int i = 0; i < e_num; i++)
//	{
//		int a, b, c;
//		scanf("%d %d %d", &a, &b, &c);
//		v[a].push_back(make_pair(b, c));
//		v[b].push_back(make_pair(a, c));
//	}
//	//1���������� �����ؼ� Ž��
//	printf("%d\n", chk(1));
//	return 0;
//}

//https://www.acmicpc.net/problem/1197
//�ּ� ���д� Ʈ��(ũ�罺Į)
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
////����
//struct Edge {
//	int start, end, cost;
//	//�ڿ����� ũ�� return 1, else 0
//	//�޸� �Ƴ����� �ּҰ��� �����ؼ� bool������ ���Ѱ�.
//	//�����Ϸ��� ���� ���� ����� ���޵��� �������� �����Ƿ� const���
//	bool operator < (const Edge &other) const {
//		return cost < other.cost;
//	}
//};
//int p[10001];
////ã��
//int Find(int x) {
//	if (x == p[x]) {
//		return x;
//	}
//	else {
//		return p[x] = Find(p[x]);
//	}
//}
////����
//void Union(int x, int y) {
//	x = Find(x);
//	y = Find(y);
//	p[x] = y;
//}
//
//int main() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//	//�Է�
//	for (int i = 1; i <= n; i++) {
//		p[i] = i;
//	}
//	vector<Edge> a(m);
//	for (int i = 0; i<m; i++) {
//		scanf("%d %d %d", &a[i].start, &a[i].end, &a[i].cost);
//	}
//	//����
//	sort(a.begin(), a.end());
//	int ans = 0;
//	//Ž��
//	for (int i = 0; i < m; i++) {
//		Edge e = a[i];
//		int x = Find(e.start);
//		int y = Find(e.end);
//		if (x != y) {
//			Union(e.start, e.end);
//			ans += e.cost;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}