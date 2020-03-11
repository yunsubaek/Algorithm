#include<iostream>
using namespace std;
typedef unsigned long long ll;
int main()
{
	ll n, m, result = 0, cnt_t = 0, cnt_f = 0, cnt_t2 = 0, cnt_f2 = 0, cnt_t3 = 0, cnt_f3 = 0;
	cin >> n >> m;
	if (n == 0 || n == 1)cout << 0 << endl;
	else if (m == 0 || m == 1)cout << 0 << endl;
	else
	{
		//n
		for (ll i = 2; i <= n; i *= 2)
			cnt_t += n / i;

		for (ll i = 5; i <= n; i *= 5)
			cnt_f += n / i;

		//r
		for (ll i = 2; i <= m; i *= 2)
			cnt_t2 += m / i;

		for (ll i = 5; i <= m; i *= 5)
			cnt_f2 += m / i;

		//n-r
		for (ll i = 2; i <= n - m; i *= 2)
			cnt_t2 += (n - m) / i;

		for (ll i = 5; i <= n - m; i *= 5)
			cnt_f2 += (n - m) / i;
		result = cnt_t - cnt_t2 - cnt_t3 > cnt_f - cnt_f2 - cnt_f3 ? cnt_t - cnt_t2 - cnt_t3 : cnt_f - cnt_f2 - cnt_f3;
		cout << result << endl;
	}
}