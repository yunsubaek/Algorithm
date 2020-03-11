////https://www.acmicpc.net/problem/2579
////계단 오르기
//#include "bits_stdc++.h"
//#define INF 1000000000
//using namespace std;
//int n, arr[302], dp[302][3];
//
//int chk(int idx, int up)
//{
//	if (up == 3)return -INF;
//	if (idx == n)return arr[idx];
//	if (idx > n)return -INF;
//	int &ret = dp[idx][up];
//	if (ret != -1)return ret;
//	ret = max(chk(idx + 1, up + 1) + arr[idx], chk(idx + 2, 1) + arr[idx]);
//	return ret;
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	memset(dp, -1, sizeof(dp));
//	printf("%d\n", chk(0, 0));
//	return 0;
//}
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

bool check[5000001]; // min + i가 제곱수인지 아닌지

int main()
{
	vector<long long int> zegop;

	long long int min, max;
	cin >> min >> max;

	for (long long int i = 2;; i++)
	{
		if (i*i > max) break;
		zegop.push_back(i*i);
	}
	long long int answer = 0;
	int size = zegop.size();
	for (int i = 0; i < size; i++)
	{
		for (long long int j = (min / zegop[i])*zegop[i]; j <= max; j += zegop[i])
		{
			if (j - min < 0) continue;
			if (check[j - min] == 0)
			{
				check[j - min] = 1;
				answer++;
			}
		}
	}
	cout << max - min - answer + 1 << endl;
	return 0;
}