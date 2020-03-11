#include<iostream>
#define SIZE 1000002
using namespace std;
int arr[SIZE] = { 0 };
int cnt = 0;

int find_(int x)
{
	if (x == arr[x])return x;
	else 
		return arr[x]= find_(arr[x]);
}

void union_(int x, int y)
{
	x = find_(x);
	y = find_(y);
	arr[y] = x;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n;i++)
		arr[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cnt = 0;
		if (a == 0)
		{
			union_(b, c);
		}
		else
		{
			int z = find_(b);
			int x = find_(c);
			if (x == z)printf("YES\n");
			else printf("NO\n");
		}
	}
}