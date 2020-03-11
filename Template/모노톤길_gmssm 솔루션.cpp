#include "bits_stdc++.h"
#define INF 1000000000
using namespace std;

int t, n, m; vector< vector<int> > arr; pair<int, int> ans[100001];
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		arr = vector< vector<int> >
			(100001);

		scanf("%d", &n);
		for (int i = 0; i<n; i++)
		{
			int x, y; scanf("%d %d", &x, &y);
			arr[x].push_back(y);
		}

		for (int i = 0; i <= 100000; i++) sort(arr[i].begin(), arr[i].end());


		int prevy = 0, cnt = 1;
		for (int i = 0; i <= 100000; i++)
		{
			if (arr[i].size() == 0) continue;

			if (arr[i][0] == prevy)
			{
				for (int j = 0; j<(int)arr[i].size(); j++)
				{
					ans[cnt++] = make_pair(i, arr[i][j]);

				}
				prevy = arr[i][(int)arr[i].size() - 1];
				continue;
			}

			else if (arr[i][(int)arr[i].size() - 1] == prevy)
			{
				for (int j = (int)arr[i].size() - 1; j >= 0; j--)
				{
					ans[cnt++] = make_pair(i, arr[i][j]);

				}
				prevy = arr[i][0];
			}
		}

		scanf("%d", &m);
		for (int i = 0; i<m; i++)
		{
			int num; scanf("%d", &num);
			printf("%d %d\n", ans[num].first, ans[num].second);
		}
	}
}
