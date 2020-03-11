#include "bits_stdc++.h"
#define SIZE 50002
using namespace std;
int n, arr[SIZE], k, cache[SIZE][3], pSum[SIZE];

// ���� i�� ������ ������ �� ���� ���� �����̰�,
// �������� ����� ����������� ������ selected�� �϶�, �ִ� �մ� �� ��ȯ
int sol(int i, int selected)
{
	// 3���� ����������� ��� ����Ѱ�� >> �� �¿�� �����Ƿ� 0 ��ȯ.
	if (selected == 3) return 0;

	// ��� ������ ����� ��� >> �� �¿�� �����Ƿ� 0��ȯ.
	if (i == n + 1) return 0;

	// �޸������̼�
	int& ret = cache[i][selected]; if (ret != -1) return ret;

	// i�� ������ �����ϴ� ���
	// ������ k���Ǹ�ŭ ������ �־�� ���� �����ϴ�.
	// �κ����� �̿��ؼ� O(1) Ÿ�ӿ� ����Ѵ�.
	if (i + k - 1 <= n)
		ret = max(ret, pSum[i + k - 1] - pSum[i - 1] + sol(i + k, selected + 1));

	// �������� �ʴ°��
	// i+1�� ���Ǻ��� ����Ѵ�.
	ret = max(ret, sol(i + 1, selected));
	return ret;
}
int main()
{
	// �κ��� �迭 ä���
	scanf("%d", &n); for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); pSum[i] = pSum[i - 1] + arr[i]; }
	scanf("%d", &k); for (int i = 0; i < SIZE; i++) for (int j = 0; j < 3; j++) cache[i][j] = -1;
	printf("%d\n", sol(1, 0));
}