//https://www.acmicpc.net/problem/2805
//나무 자르기
#include <iostream>
#define SIZE 1000002
using namespace std;
long long n, m, arr[SIZE] = { 0 }, max_ = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
        scanf("%lld", &arr[i]);
		if (arr[i] > max_)max_ = arr[i];
	}
	long long l = 0, r = max_;
	long long mid = (l + r) / 2;
	while (l <= r)
	{
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] - mid > 0)sum += (arr[i] - mid);
		}
		if (sum < m) r = mid - 1;
		else l = mid + 1;
		mid = (l + r) / 2;
	}
	printf("%lld\n", mid);
	return 0;
}