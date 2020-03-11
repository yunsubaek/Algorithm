//https://www.acmicpc.net/problem/11726
#include<iostream>
#define SIZE 1002
using namespace std;

int main()
{
	int n, arr[SIZE] = { 0 };
	cin >> n;
	arr[1] = 1;
	for (int i = 2; i <= n + 1; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	cout << arr[n + 1] << endl;
}