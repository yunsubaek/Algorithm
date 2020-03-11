//https://www.acmicpc.net/problem/1759#
//암호만들기
#include "bits_stdc++.h"
using namespace std;
int n, m;
char arr[16], temp[16];

void search(int cnt,int idx)
{
	if (cnt > n || idx > m)return;
	if (cnt == n)
	{
		bool flag = 0;
		for (int i = 0; i < n; i++)
			if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')flag = 1;
		if (flag)
		{
			for (int i = 0; i < n; i++)
				printf("%c", temp[i]);
			printf("\n");
		}
		return;
	}
	temp[cnt] = arr[idx];
	search(cnt + 1, idx + 1);
	temp[cnt] = arr[idx];
	search(cnt, idx + 1);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	sort(arr, arr + m);
	search(0, 0);
	return 0;
}