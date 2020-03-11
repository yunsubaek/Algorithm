//https://www.acmicpc.net/problem/2610
//dfs or bfs && �÷��̵�(��ä���� ���� ������ ��Ʈ������ ��)
//ȸ���غ�
#include "bits_stdc++.h"
using namespace std;
int N, M;
int Map[101][101];
bool trip[101];
int group[101];
vector<int> ans;
void search(int v, int k) {
	trip[v] = true;
	group[v] = k;
	for (int i = 1; i <= N; i++)
		if (Map[v][i] == 1 && !trip[i])
			search(i, k);
}
int main() {
	cin >> N >> M;
	int a, b;
	memset(Map, 0x3f, sizeof(Map));
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		Map[a][b] = Map[b][a] = 1;
	}
	//�׷� ����
	int K = 0;
	for (int i = 1; i <= N; i++)
		if (!trip[i]) {
			K++;
			search(i, K);
		}
	//�� ���ϰ�
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (i == j || k == i || k == j)
					continue;
				if (Map[i][j] > Map[i][k] + Map[k][j])
					Map[i][j] = Map[i][k] + Map[k][j];
			}
	//���Ѱ��� �������� �׷��� ����ŭ ���鼭 �ش� �׷��� �ִ밪�� ����
	for (int k = 1; k <= K; k++) {
		int min_index;
		int min_value = 0x3f3f3f3f;
		for (int i = 1; i <= N; i++)
			if (group[i] == k) {
				int max_value = -1;
				for (int j = 1; j <= N; j++)
					if (Map[i][j] != 0x3f3f3f3f)
						max_value = max(max_value, Map[i][j]);
				if (min_value > max_value) {
					min_value = max_value;
					min_index = i;
				}
			}
		ans.push_back(min_index);
	}
	//�����ؼ�(���� �׷��� �ڿ� ���� ��찡 ����Ƿ�)
	sort(ans.begin(), ans.end());
	//���
	printf("%d\n", K);
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}