#include<iostream>
using namespace std;

int main()
{
	char arr[102] = { 0 };
	int alpha[26] = { 0 };
	cin >> arr;
	for (int i = 0; arr[i]; i++)
	{
		alpha[arr[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i] << ' ';
	}
	cout << endl;
}