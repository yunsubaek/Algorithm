//≈∏¿œπ‚±‚
//https://www.acmicpc.net/problem/6988
#include<stdio.h>
int T[3000];
int C[1100000];
int main() {
	int N, i, j, k, sum, P, res = 0, cnt;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &T[i]);
		C[T[i]]++;
	}
	for (i = 0; i<N; i++) {
		for (j = i + 1; j<N; j++) {
			sum = cnt = 0;
			for (k = T[i]; k <= T[N - 1]; k += T[j] - T[i]) {
				if (!C[k]) break;
				sum += k;
				cnt++;
			}
			if (res<sum && cnt>2) res = sum;
		}
	}
	printf("%d", res);
}