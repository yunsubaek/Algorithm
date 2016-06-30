#include "bits_stdc++.h"
#define MIN(a,b)   ((a) < (b) ? (a) : (b))
using namespace std;


int d[3][3];

int main()
{
	int N = 1;
	int testcase = 1;

	while (true)
	{
		scanf("%d", &N);

		if (N == 0)
			break;

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		d[0][0] = a;
		d[0][1] = b;
		d[0][2] = c;

		for (int i = 1; i < N; i++)
		{
			scanf("%d %d %d", &a, &b, &c);

			if (i == 1)
			{
				d[1][0] = d[0][1] + a;
				d[1][1] = MIN(d[0][1], MIN(d[1][0], d[0][1] + d[0][2])) + b;
				d[1][2] = MIN(d[0][1], MIN(d[1][1], d[0][1] + d[0][2])) + c;

			}

			else
			{
				d[1][0] = MIN(d[0][0], d[0][1]) + a;
				d[1][1] = MIN(d[1][0], MIN(d[0][0], MIN(d[0][1], d[0][2]))) + b;
				d[1][2] = MIN(d[1][1], MIN(d[0][1], d[0][2])) + c;
			}

			d[0][0] = d[1][0];
			d[0][1] = d[1][1];
			d[0][2] = d[1][2];
		}

		printf("%d. %d\n", testcase, d[1][1]);
		testcase++;
	}

	return 0;
}