#include<iostream>
#define SIZE 89
using namespace std;
long long arr[SIZE] = { 0,1,1 };
long long total[SIZE] = { 0,1,2 };

int main()
{
	long long k;
	cin >> k;
	//피보나치 초기화
	for (int i = 3; i <= SIZE; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		total[i] = total[i - 1] + arr[i];
	}
	long long x, sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += arr[i];
		if (k <= sum)
		{
			x = i;
			break;
		}
	}
	long long s = 0;
	for (int i = x; i >= 0; i--)
	{
		if (s + arr[i] <= k)
		{
			s += arr[i];
			cout << " arr[i]=" << arr[i] << " i=" << i << " sum=" << s << endl;
		}
		if (s == k)
		{
			cout << s << endl;
			break;
		}
	}
	//cout << x;
}