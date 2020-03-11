//https://www.acmicpc.net/problem/1654
//랜선자르기
#include <iostream>
#define SIZE 10002
using namespace std;

int main()
{
	long long k, n, arr[SIZE], sum = 0, max = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max)max = arr[i];
	}
	long long l = 0, r = max, mid = sum / n;
	while (l <= r)
	{
		long long x = 0;
		for (int i = 0; i < k; i++)
		{
			if (arr[i] / mid > 0)x += arr[i] / mid;
		}
		if (x >= n)
			l = mid + 1;
		else
			r = mid - 1;
		mid = (l + r) / 2;
	}
	cout << mid << "\n";
	return 0;
}