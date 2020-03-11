#include<iostream>
#define SIZE 100002
using namespace std;
long long arr[SIZE] = { 0 }, temp[SIZE] = { 0 };

int main()
{
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
		for (int j = i - 1; j >= i-1; j--)
		{
			if ((temp[i] < temp[i] + arr[j]) || (temp[i] < temp[i] + temp[j]))
			{
				long long sum = temp[i] + arr[j] > temp[i] + temp[j] ? temp[i] + arr[j] : temp[i] + temp[j];
				temp[i] = sum;
			}
			else break;
		}
	}
	long long max = -6000000000LL;
	for (int i = 0; i < n; i++)
	{
		if (temp[i] > max)max = temp[i];
	}
	cout << max << endl;
}