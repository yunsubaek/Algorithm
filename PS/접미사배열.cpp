#include<iostream>
#define SIZE 1002
using namespace std;
char temp[SIZE][SIZE] = { 0 };

int str_len(char arr[])
{
	int i = 0;
	while (arr[i++]);
	return i - 1;
}

int str_cmp(char arr[], char temp[])
{
	int a = str_len(arr), b = str_len(temp);
	int sum = a > b ? b : a;
	//i<=sum에서 sum을 빼먹으면 안됨... 개중요크
	for (int i = 0; i<= sum; i++)
	{
		//뒤에가 크면 1 앞에가 크면 -1 => 1이면 
		if (arr[i] < temp[i]) return 1;
		else if (arr[i] > temp[i]) return -1;
	}
}

int main()
{
	char arr[SIZE] = { 0 }; 
	int chk[SIZE] = { 0 };
	cin >> arr;
	int len = str_len(arr);

	for (int i = 0; i < len; i++)
	{
		for (int j = i, x = 0; j < len; j++)
		{
			temp[i][x++] = arr[j];
		}
	}

	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			int a = str_cmp(temp[j], temp[j + 1]);
			if(a > 0)
			{
				char z[SIZE] = { 0 };
				sprintf(z, "%s", temp[j]);
				sprintf(temp[j], "%s", temp[j + 1]);
				sprintf(temp[j + 1], "%s", z);
			}
		}
	}
	for (int i = len - 1; i >= 0; i--)
		cout << temp[i] << endl;
}