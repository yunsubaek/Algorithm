#include<iostream>
#define SIZE 1000002
using namespace std;
long long int arr[SIZE] = { 0 };

int main()
{
	long long int n, m, sum = 0, min = -1, max = 0, mid = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max)max = arr[i];
	}

	mid = sum / m;

	while ((min != mid) && (max!=mid))
	{
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] / mid > 0)sum += arr[i] / mid;
		}
		if (sum < m)
			max = mid;
		else
			min = mid;
		mid = (min + max) / 2;
	}
	cout << mid << endl;
}