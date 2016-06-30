////https://www.acmicpc.net/problem/1744
////�� ����
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main() {
//	int n;
//	vector<int> plus;
//	vector<int> minus;
//	cin >> n;
//	int zero = 0;
//	int one = 0;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		if (x == 1) {
//			one += 1;
//		}
//		else if (x > 0) {
//			plus.push_back(x);
//		}
//		else if (x < 0) {
//			minus.push_back(x);
//		}
//		else {
//			zero += 1;
//		}
//	}
//	sort(plus.begin(), plus.end());
//	reverse(plus.begin(), plus.end());
//	sort(minus.begin(), minus.end());
//	if (plus.size() % 2 == 1) {
//		plus.push_back(1);
//	}
//	if (minus.size() % 2 == 1) {
//		minus.push_back(zero > 0 ? 0 : 1);
//	}
//	int ans = one;
//	for (int i = 0; i < plus.size(); i += 2) {
//		ans += plus[i] * plus[i + 1];
//	}
//	for (int i = 0; i < minus.size(); i += 2) {
//		ans += minus[i] * minus[i + 1];
//	}
//	cout << ans << '\n';
//	return 0;
//}

////�� ����(dp)
//#include "bits_stdc++.h"
//using namespace std;
//
//int arr[10000];
//int dp[10000]; // dp[i] = i ��°���� ���� ���� �� �ִ밪
//int n;
//
//int search(int idx)
//{
//	if (idx >= n)return 0;
//	int& ret = dp[idx];
//	if (ret != -1)return ret;
//	ret = arr[idx] + search(idx + 1);
//	if (idx + 1 < n)ret = max(ret, arr[idx] * arr[idx + 1] + search(idx + 2));
//	return ret;
//}
//
//int main()
//{
//	memset(dp, -1, sizeof(dp));
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		scanf("%d", &arr[i]);
//	sort(arr, arr + n);
//	printf("%d\n", search(0));
//	return 0;
//}