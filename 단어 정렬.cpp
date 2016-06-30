//정렬 어떻게해야 하나..?
#include<iostream>
#define SIZE 20002
using namespace std;
char arr[SIZE][52] = { 0 };
int a_num[SIZE] = { 0 };

//문자열 길이
int str_len(char arr[])
{
	int i = 0;
	while (arr[i++]);
	return i - 1;
}
//문자열 비교
int str_cmp(char a[], char b[])
{
	int n = str_len(a);
	for (int i = 0; i < n; i++)
	{
		//a가 알파벳에서 뒤에 있으면 1, 아니면 -1
		if (a[i] > b[i])
			return 1;

		else if (a[i] < b[i])
			return -1;
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	//input
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &arr[i]);
		a_num[i] = str_len(arr[i]);
	}

	//sort
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			//길이로 정렬
			if (a_num[j] > a_num[j + 1])
			{
				char temp[52] = { 0 };
				sprintf(temp, "%s", arr[j]);
				sprintf(arr[j], "%s", arr[j + 1]);
				sprintf(arr[j + 1], "%s", temp);

				int tmp = a_num[j];
				a_num[j] = a_num[j + 1];
				a_num[j + 1] = tmp;
			}
			//길이가 같을 경우 사전순으로 정렬
			if (a_num[j] == a_num[j + 1])
			{
				char temp[52] = { 0 };
				if (str_cmp(arr[j], arr[j + 1]) == 1)
				{
					sprintf(temp, "%s", arr[j]);
					sprintf(arr[j], "%s", arr[j + 1]);
					sprintf(arr[j + 1], "%s", temp);
				}
			}
		}
	}
	//output
	for (int i = 0; i < n; i++)
	{
		//같은 문자의 경우 하나만 출력
		if (str_len(arr[i]) == str_len(arr[i + 1]))
		{
			if (str_cmp(arr[i], arr[i + 1]) != 0)
				printf("%s\n", arr[i]);
		}
		//아닐경우 전부 출력
		else printf("%s\n", arr[i]);
	}
}