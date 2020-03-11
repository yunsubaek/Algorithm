#include "bits_stdc++.h"
#define SIZE 1002
using namespace std;
int t, w, arr[SIZE], dp[1002][32][2];

int chk(int pos, int turn, int now) {
	if (pos == t && turn <= w) return 0;
	if (turn > w)return 0;
	int &ret = dp[pos][turn][now];
	if (ret != -1)return ret;
	ret = max(chk(pos + 1, turn + 1, 3 - now), chk(pos + 1, turn, now)) + (now == arr[pos] ? 1 : 0);
	return ret;
}

int main() {
	cin >> t >> w;
	for (int i = 0; i < t; i++) {
		scanf("%d", &arr[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", max(chk(0, 0, 1), chk(0, 1, 2)));
}