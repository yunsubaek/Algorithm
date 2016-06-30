//https://www.acmicpc.net/problem/11722
#include<iostream>
#define SIZE 1002
using namespace std;

int main()
{
	int n, arr[SIZE] = { 0 }, temp[SIZE] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		temp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && temp[i] < temp[j] + 1)
				temp[i] = temp[j] + 1;
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp[i] > max)
			max = temp[i];
	}
	cout << max << endl;
}