#include<iostream>
using namespace std;

unsigned long long int str_len(unsigned long long int arr)
{
	unsigned long long int i = 1;
	if (arr < 10) return 1;
	else
	{
		while (arr / 10 > 9) { arr /= 10; i++; }
	}
	return i + 1;
}

unsigned long long int pow_(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int n = 1;
	for (int i = 0; i < b; i++)
	{
		n *= a;
	}
	return n;
}

int main()
{
	unsigned long long int sum = 0;
	unsigned long long int arr[4] = { 0 };
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	int size[4] = { 0 };
	for (int i = 0; i < 4; i++)
		size[i] = str_len(arr[i]);
	sum += arr[0] * pow_(10, size[1]) + arr[2] * pow_(10, size[3]) + arr[1] + arr[3];
	cout << sum << endl;
}