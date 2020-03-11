#include<iostream>
using namespace std;

int str_len(char arr[])
{
	int i = 0;
	while (arr[i++]);
	return i - 1;
}

int main()
{
	char arr[102] = { 0 };
	int alpha[26] = { 0 };
	int temp[26] = { 0 };
	cin >> arr;
	int len = str_len(arr);
	for (int i = 0; i < 26; i++)
	{
		temp[i] = -1;
	}
	for (int i = 0; i < len; i++)
	{
		alpha[arr[i] - 'a'] ++;
		if (temp[arr[i] - 'a'] == -1) temp[arr[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << temp[i] << ' ';
	}
	cout << '\n';
}