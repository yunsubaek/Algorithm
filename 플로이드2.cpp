#include "bits_stdc++.h"
#define SIZE 102
using namespace std;

int n, m, arr[SIZE][SIZE], temp[SIZE][SIZE];
stack<int> st;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		if(!arr[from][to])arr[from][to] = cost;
		else arr[from][to] = min(arr[from][to], cost);
		temp[from][to] = from;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || i == k)continue;
				if (arr[i][k] && arr[k][j])
					if (arr[i][k] + arr[k][j] < arr[i][j] || arr[i][j] == 0) {
						arr[i][j] = arr[i][k] + arr[k][j];
						temp[i][j] = temp[k][j];
					}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				printf("0\n");

			else if (temp[i][j] == 0)
				printf("0\n");

			else
			{
				int from = i;
				int to = j;
				st.push(to);

				while (from != to)
				{
					int dist = temp[from][to];
					to = dist;
					st.push(to);
				}

				printf("%d ", st.size());
				while (!st.empty())
				{
					printf("%d ", st.top());
					st.pop();
				}
				printf("\n");
			}
		}
	}
	return 0;
}