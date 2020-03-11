//https://www.acmicpc.net/problem/9466
//�� ������Ʈ
#include <cstdio>
int a[100001];
int d[100001];
int s[100001];
int n;
int dfs(int x, int cnt, int step) {
	while (true) {
		if (d[x] != 0) {
			if (step != s[x]) {
				return 0;
			}
			return cnt - d[x];
		}
		d[x] = cnt;
		s[x] = step;
		x = a[x];
		cnt += 1;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i] = 0;
			s[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}