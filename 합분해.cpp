//https://www.acmicpc.net/problem/2225
//ÇÕºÐÇØ
#include "bits_stdc++.h"
using namespace std;

int main()
{
	int n, k, d[202][202] = { 1 };
	const int mod = 1000000000;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[k][n] << endl;
}