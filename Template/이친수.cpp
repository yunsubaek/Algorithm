//https://www.acmicpc.net/problem/2193
#include<iostream>
using namespace std;

int main()
{
	unsigned long long int arr[94] = { 1,1, };
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n - 1] << endl;
}