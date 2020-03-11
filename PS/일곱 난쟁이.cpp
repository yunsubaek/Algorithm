#include<iostream>
#define SIZE 9
using namespace std;
int arr[SIZE] = { 0 };
int temp[7] = { 0 };
int sum = 0;
bool flag = 0;
int chk(int a, int b)
{
	if (flag == 1)return 0;
	if (sum == 100)
	{
		for (int i = 0; i < 7; i++)
		{
			cout << temp[i] << '\n';
		}
		flag = 1;
		return 0;
	}
	else if (sum > 100 || a > 6 || b > 9)return 0;

	temp[a] = arr[b];
	sum += arr[b];
	chk(a + 1, b + 1);

	temp[a] = arr[b];
	sum -= arr[b];
	chk(a, b + 1);
}

int main()
{
	//input
	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}
	//sort
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1 - i; j++)
		{
			int tmp;
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	chk(0, 0);
}