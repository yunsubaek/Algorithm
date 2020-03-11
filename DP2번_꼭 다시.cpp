#include<iostream>
#define SIZE 1002
using namespace std;

int main()
{
	int arr[SIZE] = { 0 };
	int temp[SIZE] = { 0 };
	int n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (temp[j] < temp[i] && temp[i] < temp[j] + arr[i])
				temp[i] = temp[j] + arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (temp[i] > max)
			max = temp[i];
	}
	cout << max << endl;
	return 0;
}