//Jennifer Soft - A
#include <iostream>
#include <cstdio>
#include <algorithm>
#define SIZE 1000002
using namespace std;

struct alpha
{
	int cnt, pos;
};

bool cmp(const alpha &a, const alpha &b)
{
	if (a.cnt == b.cnt)
		return a.pos < b.pos;
	return a.cnt < b.cnt;
}

char s[SIZE];
alpha a[26];

int main()
{
	scanf("%s", &s);
	int len = strlen(s);
	//��ġ �ʱ�ȭ
	for (int i = 0; i < 26; i++)
		a[i].pos = i;
	//���� ī��Ʈ
	for (int i = 0; i < len; i++)
		a[s[i] - 'A'].cnt++;
	//����
	sort(a, a + len, cmp);
	for (int i = 0; i < len; i++)
		if (a[i].cnt != 0)
			for (int j = 0; j < a[i].cnt; j++)
				printf("%c", a[i].pos + 'A');
	printf("\n");
	return 0;
}