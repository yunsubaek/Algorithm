#include<iostream>
#define SIZE 100002
#define INF 8//2000000000
#define MIN(x,y) ((x)>(y)?(y):(x))
using namespace std;
int dp[SIZE][5][5], price[5][5], temp[SIZE], a, idx = -1;

int chk(int i, int lf, int rf)
{
	int &ret = dp[i][lf][rf];
	getchar();
	printf("i=%d lf=%d rf=%d ret=%d\n", i, lf, rf, ret);
	if (i == idx)return 1;
	if (i > idx)return -INF;
	if (ret != 0)return ret;
	ret = MIN(chk(i + 1, temp[i + 1], rf) + price[temp[i]][temp[i + 1]], chk(i + 1, lf, temp[i + 1]) + price[temp[i]][temp[i + 1]]);
	return ret;
}

int main()
{
	//이동거리 저장. 사용하는 힘의 비용
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (i == j)price[i][j] = 1;
			else if (i - j == 2 || j - i == 2)price[i][j] = 3;
			else if (i == 0)price[i][j] = INF;
			else if (j == 0)price[i][j] = INF;
			else price[i][j] = 2;
		}
	}
	price[0][0] = INF, price[0][2] = INF, price[2][0] = INF;
	//0이 나올때까지 입력
	while (scanf("%d", &a))
	{
		if (a == 0)break;
		temp[++idx] = a;
	}
	cout << chk(0, 0, 0);
}