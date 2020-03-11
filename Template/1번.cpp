//앞뒤 보고 갯수 세서 정렬
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
	int s, d, value;
};

vector<node> V;

deque<int> dQ;

int d[30][30];

bool cmp(const node & a, const node & b)
{
	if (a.value > b.value) return true;
	else return false;
}

int main()
{
	char c;
	while (scanf("%c", &c) == 1)
	{
		if (c == ' ' || c == '\n')
		{
			d[dQ.front()][dQ.back()]++;
			dQ.clear();
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c -= 'A';
			dQ.push_back(c);
		}
		else if (c >= 'a' && c <= 'z')
		{
			c -= 'a';
			dQ.push_back(c);
		}
	}

	d[dQ.front()][dQ.back()]++;
	dQ.clear();

	for (int i = 0; i <= 'z' - 'a'; i++)
	{
		for (int j = 0; j <= 'z' - 'a'; j++)
		{
			if (d[i][j] > 0) V.push_back({ i, j, d[i][j] });
		}
	}

	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < V.size(); i++)
	{
		printf("%c%c , %d\n", V[i].s + 'a', V[i].d + 'a', V[i].value);
	}
	return 0;
}