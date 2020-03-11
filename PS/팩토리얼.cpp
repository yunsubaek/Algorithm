#include<iostream>
using namespace std;

int main()
{
	int n, arr[14] = { 0 };
	cin >> n;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] * i;
	}
	cout << arr[n] << endl;
}