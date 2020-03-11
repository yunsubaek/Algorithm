#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
	char Own;
	int prd;
};

vector<node> procs;

bool cmp(const node & a, const node & b)
{
	if (a.prd < b.prd) return true;
	else return false;
}

bool cmp2(const node & a, const node & b)
{
	if (a.Own < b.Own) return true;
	else return false;
}

int main()
{
	char str[1000];
	char Now;
	while (cin >> str)
	{
		int len = strlen(str);
		if (len == 1)
		{
			if (str[0] >= 'A' && str[0] <= 'Z')
			{
				Now = str[0];
			}
		}

		if (len > 6)
		{
			char num[100] = { 0, };
			int nidx = 0;
			for (int i = 0; i < len; i++)
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					num[nidx++] = str[i];
				}
			}

			int inum = atoi(num);
			node Product;
			Product.Own = Now;
			Product.prd = inum;
			procs.push_back(Product);
		}
	}

	sort(procs.begin(), procs.end(), cmp);

	int gNum = 1;
	int bNum = 0;
	for (int i = 0; i < procs.size(); i++)
	{
		if (bNum == 0 || bNum == 3)
		{
			if (procs.size() > i + 2)
			{
				sort(procs.begin() + i, procs.begin() + i + 3, cmp2);
			}
			else
			{
				sort(procs.begin() + i, procs.end(), cmp2);
			}
		}
		if (bNum == 3)
		{
			printf("\n");
			bNum = 0;
			gNum++;
		}

		if (bNum == 0)
		{
			cout << "그룹 " << gNum << ": ";
		}

		cout << "상자(" << procs[i].Own << procs[i].prd << "), ";
		bNum++;
	}


	return 0;
}