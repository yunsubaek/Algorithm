//https://www.acmicpc.net/problem/9095
#include<iostream>
#define SIZE 12
using namespace std;
int arr[3] = { 1, 2, 3 }, n, cnt;

void chk(int sum)
{
	if (sum > n)return;
	if (sum == n) { cnt++; return; }
	for (int i = 0; i < 3; i++)
		chk(sum + arr[i]);
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		cnt = 0;
		scanf("%d", &n);
		chk(0);
		printf("%d\n", cnt);
	}
}