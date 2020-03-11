#include<iostream>
#include<cstdio>
#define SIZE 102
using namespace std;

int main()
{
	char arr[SIZE] = { 0 };
	fgets(arr, SIZE, stdin);
	for (int i = 0; arr[i] != '\n'; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'm')arr[i] += 13;
		else if (arr[i] >= 'n' && arr[i] <= 'z')arr[i] -= 13;
		else if (arr[i] >= 'A' && arr[i] <= 'M')arr[i] += 13;
		else if (arr[i] >= 'N' && arr[i] <= 'Z')arr[i] -= 13;
		cout << arr[i];
	}
	cout << endl;
}