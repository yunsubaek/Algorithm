#include <iostream>
#define inf 2000000000
#define SIZE 1002
using namespace std;

int arr[SIZE][SIZE] = { 0 };
int temp[SIZE] = { 0 };
bool chk[SIZE] = { 0 };

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			arr[i][j] = inf;
		}
	}
	int min_;
	scanf("%d", &min_);
	for (int i = 0; i<min_; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (arr[x][y] > z)
		{
			arr[x][y] = z;
		}
	}

	int start, end;
	scanf("%d %d", &start, &end);
	for (int i = 1; i <= n; i++) 
	{
		temp[i] = inf;
	}
	temp[start] = 0;

	for (int k = 0; k<n - 1; k++) 
	{
		int min_ = inf + 1;
		int x = -1;
		for (int i = 1; i <= n; i++) 
		{
			if (chk[i] == false && min_ > temp[i]) 
			{
				min_ = temp[i];
				x = i;
			}
		}
		chk[x] = true;
		for (int i = 1; i <= n; i++) 
		{
			if (temp[i] > temp[x] + arr[x][i])
			{
				temp[i] = temp[x] + arr[x][i];
			}
		}
	}
	printf("%d\n", temp[end]);
	return 0;
}