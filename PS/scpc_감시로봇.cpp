//이분탐색 ㄲ
//갓트리 소스 참고함..
#include <iostream>
#include <stdio.h>
#define SIZE 100002
#define INF 1000000000
#define min(x,y) ((x)>(y)?(y):(x))
using namespace std;
int n, r, l;
int arr[SIZE] = { 0 };

bool possible(int data)
{
	int left = 0;
	int right = l;
	for (int i = 0; i < n; i++) {
		int le = arr[i] - data - r;
		int ri = arr[i] + data + r;
		if (!(le <= left&&left <= ri))
			continue;
		left += min(r * 2, arr[i] + data + r - left);
		if (left >= right)
			return true;
	}
	return false;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int itr = 0; itr < tc; itr++)
	{
		scanf("%d %d %d", &n, &r, &l);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		int result = 0;
		//impossible
		if (l > 2 * r*n)
		{
			printf("Case #%d\n", itr + 1);
			printf("-1\n");
			continue;
		}
		//possible
		int min = 0;
		int max = 2 * INF;
		result = 2 * INF;
		while (max >= min)
		{
			unsigned int mid = (min + max) / 2;
			if (possible(mid))
			{
				max = mid - 1;
				result = min(result, mid);
			}
			else
			{
				min = mid + 1;
			}
		}
		//output
		printf("Case #%d\n", itr + 1);
		printf("%d\n", result);
	}
	return 0;
}