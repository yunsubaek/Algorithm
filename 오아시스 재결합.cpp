//https://www.acmicpc.net/problem/3015#
//오아시스 재결합(백준소스 베낌..복습!)
#include "bits_stdc++.h"
#define SIZE 500002
using namespace std;
int n, a[SIZE];
stack<pair<int,int> > s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i<n; i++) {
		pair<int, int> p = { a[i], 1 }; while (!s.empty()) {
			if (s.top().first <= a[i]) {
				ans += (long long)s.top().second; if (s.top().first == a[i]) {
					p.second += s.top().second;
				}
				s.pop();
			}
			else {
				break;
			}
		}
		if (!s.empty()) ans += 1LL; s.push(p);
	}
	cout << ans << endl;
}