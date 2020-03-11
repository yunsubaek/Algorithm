//disjoint set ¹®ÀÚ¿­
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<string, string> P;
map<string, int> M;
map<string, bool> chk;
vector<string> arr;

string Find(string str)
{
	if (P[str] == str)
	{
		return str;
	}
	else
	{
		return P[str] = Find(P[str]);
	}
}

void Union(string X, string Y)
{
	X = Find(X);
	Y = Find(Y);
	P[Y] = X;
}

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		char c, str[100] = { 0, };
		int v, num = 0;

		while (scanf("%c", &c))
		{
			if (c == '\n') continue;
			if (c == ',') break;

			str[num++] = c;
		}
		cin >> v;

		M[str] = v;
		P[str] = str;
		arr.push_back(str);
	}

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		char c, str1[100] = { 0, }, str2[100] = { 0, }, str[100] = { 0, };
		int v, num = 0, s1 = 0, s2 = 0;

		cin >> str;

		while (str[num] != ',')
		{
			str1[s1++] = str[num++];
		}
		num++;
		while (str[num] != NULL)
		{
			str2[s2++] = str[num++];
		}

		Union(str1, str2);
		M[P[str1]] += M[str2];
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (chk[P[arr[i]]] == false)
		{
			chk[P[arr[i]]] = true;
			cout << P[arr[i]] << ',' << M[P[arr[i]]] << '\n';
		}
	}

	return 0;
}