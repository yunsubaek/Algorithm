//https://www.acmicpc.net/problem/2841
#include<iostream>
#define SIZE 300002
using namespace std;
int stack[6][SIZE];
int top[6] = { -1,-1,-1,-1,-1,-1 }, cnt = 0;

void push(int i, int data)
{
	stack[i][++top[i]] = data;
}

void pop(int i)
{
	stack[i][top[i]--] = '\0';
}

int main()
{
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		bool flag = 0;
		//스택에 있는 값이 클 경우(넣는 값이 들어있는 값보다 클 경우)
		if (stack[a - 1][top[a - 1]] > b)
		{
			while (stack[a - 1][top[a - 1]] > b)
			{
				pop(a - 1);
				cnt++;
			}
			flag = 1;
			if (stack[a - 1][top[a - 1]] != b)
			{
				push(a - 1, b);
				cnt++;
			}
		}
		//스택에 있는 값이 작을 경우(넣는 값이 들어있는 값보다 작을 경우)
		else if (stack[a - 1][top[a - 1]] < b)
		{
			push(a - 1, b);
			cnt++;
		}
	}
	cout << cnt << endl;
}