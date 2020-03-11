//https://www.acmicpc.net/problem/6549
//히스토그램에서 가장 큰 직사각형
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int Q, N, M;

long long heights[100005];
stack<int> st;
stack<int> st2;

int main() {

	scanf("%d", &N);
	while (N != 0) {

		long long ret = 0;
		for (int i = 1; i <= N; i++)
			scanf("%d", &heights[i]);
		heights[0] = -1;
		heights[N + 1] = 0;
		st.push(0);
		st2.push(0);
		for (int i = 1; i <= N + 1; i++) {
			long long now = heights[i];
			int stackLeft = i;
			while (true) {
				int hi = st.top();
				int hl = st2.top();
				if (heights[hi] <= now) break;
				long long di = (i - hl) * heights[hi];
				ret = MAX(di, ret);
				stackLeft = hl;
				st.pop();
				st2.pop();
			}
			if (heights[st.top()] != now) {
				st.push(i);
				st2.push(stackLeft);
			}
		}
		printf("%lld", ret);
		scanf("%d", &N);

	}
	return 0;
}