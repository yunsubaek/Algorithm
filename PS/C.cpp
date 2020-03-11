////Jennifer Soft - C
#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;
int n, dp[11][1<<10];
vector <pair<int, int> > v;
int mem[11];

int dist(int s_x, int f_x, int s_y, int f_y)
{
	return pow(s_x - f_x, 2) + pow(s_y - f_y, 2);
}

int search(int idx, int visit)
{
	if (idx == n - 1)
		if (visit == ((1 << n) - 1)) return dist(10, v[idx].first, 10, v[idx].second);
	if (idx == n-1)return 0;
	int &ret = dp[idx][visit];
	if (ret != -1)return ret;
	ret = INF;
	//방문하지 않은 경우 탐색
	for (int i = 1; i <= n; i++)
	{
		if (i == idx)continue;
		if (!(i&visit))
			ret = min(ret, search(i, visit | i+1) + (v[i].first, v[idx].first, v[i].second, v[idx].second));
	}
}

int main()
{
	scanf("%d", &n);
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	v.push_back(make_pair(10, 10));
	memset(dp, -1, sizeof dp);
	int result = search(0, 1);
	cout << result << endl;
	return 0;
}












//v.push_back(make_pair(10, 10));
//int min = 1000000000;
//for (int i = 0; i < n; i++)
//{
//	int sum = 0, before_x, before_y;
//	//비트마스크로 상태 체크
//	visit |= (1 << i);
//	//시작점은 0,0이니까 0,0과의 거리 계산(x축 시작,끝,y축 시작,끝)
//	sum += dist(v[i].first, 0, v[i].second, 0);
//	before_x = v[i].first, before_y = v[i].second;
//	for (int j = 0; j < n; j++)
//	{
//		if (!(visit&(1 << j)))
//		{
//			sum += dist(v[j].first, before_x, v[j].second, before_y);
//			before_x = v[j].first, before_y = v[j].second;
//		}
//	}
//	sum += dist(10, before_x, 10, before_y);
//	if (sum < min) min = sum;
//	visit = 0;
//}
//printf("%d\n", min);