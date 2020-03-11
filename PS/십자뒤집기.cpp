#include "bits_stdc++.h"
using namespace std;
char Map[3][4];
int cache[3][4][1 << 9];
extern inline int check(int x, int y, int state) {
	state ^= (1 << x * 3 + y);
	if (x > 0)
		state ^= 1 << ((x - 1) * 3 + y);
	if (x < 2)
		state ^= 1 << ((x + 1) * 3 + y);
	if (y > 0)
		state ^= 1 << (x * 3 + y - 1);
	if (y < 2)
		state ^= 1 << (x * 3 + y + 1);
	return state;
}
int search(int x, int y, int state) {
	if (x == 3) {
		if (state == 0)
			return 0;
		else
			return 987654321;
	}
	int &ret = cache[x][y][state];
	if (y == 3)
		return ret = search(x + 1, 0, state);
	ret = search(x, y + 1, state);
	state = check(x, y, state);
	ret = min(ret, search(x, y + 1, state) + 1);
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < 3; i++)
			scanf("%s", &Map[i]);
		int state = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Map[i][j] == '*')
					state |= (1 << i * 3 + j);
		printf("%d\n", search(0, 0, state));
	}
	return 0;
}