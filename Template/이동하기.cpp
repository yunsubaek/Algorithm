#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
#define max3(a,b,c) max(max(a,b),c)
int arr[1001][1001];
int temp[1001][1001];
int n, m;
int go(int x, int y) {
	if (x > n || y > m) {
		return 0;
	}
	if (temp[x][y] > 0) {
		return temp[x][y];
	}
	temp[x][y] = go(x + 1, y) + arr[x][y];
	int tmp = go(x, y + 1) + arr[x][y];
	if (temp[x][y] < tmp) {
		temp[x][y] = tmp;
	}
	return temp[x][y];
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d\n", go(1, 1));
	return 0;
}