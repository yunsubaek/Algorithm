//https://www.acmicpc.net/problem/2352
//반도체 설계(nlogn - LIS)
#include "bits_stdc++.h"
using namespace std;
#define min(a,b) ((a)<(b))?a:b
int main()
{
	int n;
	scanf("%d", &n);
	int in[40001];
	for (int i = 1; i <= n; i++)
		scanf("%d", &in[i]);
	int D[40001] = { 0 };
	int mx = 1;
	int idx = 1;
	D[1] = in[1];
	for (int i = 2; i <= n; i++)
	{
		idx = mx;
		for (; idx != 0 && D[idx]>in[i]; idx--);
		D[++idx] = in[i];
		if (mx < idx)
			mx = idx;
	}
	memset(D, 0, sizeof(D));
	int mmx = 1;
	idx = 1;
	D[1] = in[1];
	for (int i = 2; i <= n; i++)
	{
		idx = mmx;
		for (; idx != 0 && D[idx]<in[i]; idx--);
		D[++idx] = in[i];
		if (mmx < idx)
			mmx = idx;
	}
	printf("%d", n - min(mx, mmx));
}