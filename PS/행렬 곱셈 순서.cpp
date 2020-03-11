////https://www.acmicpc.net/problem/11049
////Çà·Ä °ö¼À ¼ø¼­(for ¹®)
//#include <cstdio>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//int A[501][2];
//int N;
//int d[501][501];
//
//int main() {
//
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++)
//		scanf("%d %d", &A[i][0], &A[i][1]);
//
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			d[i][j] = INT_MAX;
//
//	// length 1
//	for (int i = 1; i <= N; i++)
//		d[i][i] = 0;
//
//	// length 2
//	for (int i = 1; i <= N - 1; i++)
//		d[i][i + 1] = A[i][0] * A[i][1] * A[i + 1][1];
//
//	// from length 3 to length N
//	for (int k = 2; k <= N - 1; k++) {
//		for (int i = 1; i <= N - k; i++) {
//			// find d[i][i+k]
//			int ans = INT_MAX;
//			for (int j = i + 1; j <= i + k; j++) { // the starting point of the second part
//				ans = min(ans, d[i][j - 1] + d[j][i + k] + A[i][0] * A[j - 1][1] * A[i + k][1]);
//			}
//			d[i][i + k] = ans;
//		}
//
//	}
//
//	printf("%d\n", d[1][N]);
//	return 0;
//}

////Çà·Ä °ö¼À ¼ø¼­(recursive)
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//
//int d[500][500];
//int h[500], w[500], n;
//
//int f(int l, int r) {
//	if (l >= r) return 0;
//	if (d[l][r] >= 0) return d[l][r];
//	int res = INT_MAX;
//	for (int i = l; i<r; i++)
//		res = min(res, f(l, i) + f(i + 1, r) + h[l] * w[i] * w[r]);
//	return d[l][r] = res;
//}
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i<n; i++) scanf("%d %d", &h[i], &w[i]);
//	memset(d, -1, sizeof(d));
//	printf("%d", f(0, n - 1));
//}