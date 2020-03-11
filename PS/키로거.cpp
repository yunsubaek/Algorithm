//https://www.acmicpc.net/problem/5397
#include<iostream>
#define SIZE 1000002
using namespace std;
char l_stack[SIZE] = { 0 }, r_stack[SIZE] = { 0 }, temp[SIZE] = { 0 };

void push(char stack[], int top, char data)
{
	stack[++top] = data;
}

void pop(char stack[], int top)
{
	if (top >= 0)
		stack[top--] = '\0';
}

int str_len(char arr[])
{
	int i = 0;
	while (arr[i++]);
	return i - 1;
}

int main()
{
	int tc;
	cin >> tc;
	for (int itr = 0; itr < tc; itr++)
	{
		cin >> temp;
		int l_top = -1, r_top = -1, len = str_len(temp);
		bool flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (temp[i] == '<')
			{
				push(r_stack, r_top, l_stack[l_top]);
				pop(l_stack, l_top);
				if (l_top != -1)
				{
					flag = 1;
					r_top++;
					l_top--;
				}
			}

			else if (temp[i] == '>')
			{
				push(l_stack, l_top, r_stack[r_top]);
				pop(r_stack, r_top);
				if (r_top != -1)
				{
					flag = 0;
					l_top++;
					r_top--;
				}
			}

			else if (temp[i] == '-')
			{
				pop(l_stack, l_top);
				if (l_top >= 0)l_top--;
			}

			else
			{
				push(l_stack, l_top++, temp[i]);
			}
		}
		cout << l_stack;
		int r_len = str_len(r_stack);
		for (int i = r_len - 1; i >= 0; i--)
			printf("%c", r_stack[i]);
		printf("\n");
		int x = 0, y = 0;
		while (l_stack[x])
		{
			l_stack[x++] = '\0';
		}
		while (r_stack[y])
		{
			r_stack[y++] = '\0';
		}
	}
}