#include "bits_stdc++.h"
#define SIZE 50002
using namespace std;
int n, arr[SIZE], k, cache[SIZE][3], pSum[SIZE];

// 현재 i번 객실을 선택할 지 말지 정할 차례이고,
// 이전까지 사용한 소형기관차의 개수가 selected개 일때, 최대 손님 수 반환
int sol(int i, int selected)
{
	// 3대의 소형기관차를 모두 사용한경우 >> 더 태울수 없으므로 0 반환.
	if (selected == 3) return 0;

	// 모든 객실을 고려한 경우 >> 더 태울수 없으므로 0반환.
	if (i == n + 1) return 0;

	// 메모이제이션
	int& ret = cache[i][selected]; if (ret != -1) return ret;

	// i번 객실을 선택하는 경우
	// 끝에서 k객실만큼 떨어져 있어야 선택 가능하다.
	// 부분합을 이용해서 O(1) 타임에 계산한다.
	if (i + k - 1 <= n)
		ret = max(ret, pSum[i + k - 1] - pSum[i - 1] + sol(i + k, selected + 1));

	// 선택하지 않는경우
	// i+1번 객실부터 고려한다.
	ret = max(ret, sol(i + 1, selected));
	return ret;
}
int main()
{
	// 부분합 배열 채우기
	scanf("%d", &n); for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); pSum[i] = pSum[i - 1] + arr[i]; }
	scanf("%d", &k); for (int i = 0; i < SIZE; i++) for (int j = 0; j < 3; j++) cache[i][j] = -1;
	printf("%d\n", sol(1, 0));
}