#include<iostream>
using namespace std;

int main()
{
	char arr[102] = { 0 };
	int l = 0;
	cin >> arr;
	while (arr[l++]);
	cout << l - 1 << endl;
}