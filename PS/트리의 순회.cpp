#include<iostream>
#define SIZE 52
using namespace std;
int tree[SIZE][2] = { 0 };

void pre(int x)
{
	if (x == -1)return;
	else
	{
		cout << char(x + 'A');
		pre(tree[x][0]);
		pre(tree[x][1]);
	}
}

void in(int x)
{
	if (x == -1)return;
	else
	{
		in(tree[x][0]);
		cout << char(x + 'A');
		in(tree[x][1]);
	}
}

void post(int x)
{
	if (x == -1)return;
	else
	{
		post(tree[x][0]);
		post(tree[x][1]);
		cout << char(x + 'A');
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (b == '.')tree[a - 'A'][0] = -1;
		else tree[a - 'A'][0] = b-'A';
		if (c == '.')tree[a - 'A'][1] = -1;
		else tree[a - 'A'][1] = c-'A';
	}
	pre(0);
	cout << '\n';
	in(0);
	cout << '\n';
	post(0);
}