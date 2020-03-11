//https://www.codeground.org/practice/practiceProbView.do?probId=16
//96.7Á¡ ¼Ò½º..
#include<iostream>
#define SIZE 100002
using namespace std;
typedef long long ll;

ll get_gcd(ll a, ll b)
{
	if (b == 0)return a;
	else return get_gcd(b, a%b);
}

int main()
{
	int nCount, gcd;
	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		int n;
		ll arr[SIZE] = { 0 };
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i == 1)gcd = arr[i] - arr[i - 1];
			else if (i != 0)gcd = get_gcd(gcd, arr[i] - arr[i - 1]);
		}
		cout << "Case #" << itr + 1 << '\n';
		if (gcd == 0)cout << 1 << '\n';
		else
		{
			ll cnt = 0;
			for (ll i = 1; i <= gcd; i++)
			{
				if (i * i >= gcd)
				{
					cnt = cnt * 2;
					if (i * i == gcd) cnt++;
					break;
				}
				else if (gcd % i == 0) cnt++;
			}
			cout << cnt << '\n';
		}
	}
	return 0;
}