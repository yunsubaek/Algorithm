//https://www.acmicpc.net/problem/1753
//�ִ� ���
#include "bits_stdc++.h"
#define SIZE 20002
#define INF 2000000000
using namespace std;
vector<pair<int,int> > v[SIZE];
int dist[SIZE];
priority_queue<pair<int, int> > pq;
int main()
{
	int v_num, e_num, st;
	scanf("%d %d %d", &v_num, &e_num, &st);
	//�������� �Է�
	for (int i = 0; i < e_num; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	//�Ÿ� INF�� �ʱ�ȭ(�������� ����)
	for (int i = 0; i < SIZE; i++)
		if(i!=st) dist[i] = INF;
	//������� �� ����ġ push.
	pq.push(make_pair(0, st));
	//pq�� �������� �ݺ�
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost)continue;
		for (int i = 0; i < v[now].size(); i++)
		{
			int to = v[now][i].first;
			int to_cost = v[now][i].second;
			if (dist[to] > cost + to_cost)
			{
				dist[to] = cost + to_cost;
				pq.push(make_pair(-dist[to], to));
			}
		}
	}
	for (int i = 1; i <= v_num; i++)
	{
		if (dist[i] != INF)printf("%d\n", dist[i]);
		else printf("INF\n");
	}
}