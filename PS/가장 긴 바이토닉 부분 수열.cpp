//https://www.acmicpc.net/problem/11054
#include<iostream>
#define SIZE 1002
using namespace std;

int main()
{
	int n, arr[SIZE] = { 0 }, tempf[SIZE] = { 0 }, tempt[SIZE] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max = 0, max_idx = 0;
	for (int i = 0; i < n; i++)
	{
		tempf[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && tempf[i] < tempf[j] + 1)
			{
				tempf[i] = tempf[j] + 1;
			}
		}
		tempt[n - i - 1] = 1;
		for (int j = n - 1; j >= n - i; j--)
		{
			if (arr[j] < arr[n - i - 1] && tempt[n - i - 1] < tempt[j] + 1)
			{
				tempt[n - i - 1] = tempt[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (tempt[i] + tempf[i]>max)
		{
			max = tempt[i] + tempf[i];
			max_idx = i;
		}
	}
	cout << max - 1 << endl;
}