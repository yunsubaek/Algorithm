#include<iostream>
using namespace std;

int main()
{
	int n, cnt_t = 0, cnt_f = 0, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t = i, f = i;
		while (t)
		{
			if (t % 2 == 0)
			{
				cnt_t++;
				t /= 2;
			}
			else break;
		}
		while (f)
		{
			if (f % 5 == 0)
			{
				cnt_f++;
				f /= 5;
			}
			else break;
		}
	}
	cnt = cnt_t > cnt_f ? cnt_f : cnt_t;
	cout << cnt << endl;
}