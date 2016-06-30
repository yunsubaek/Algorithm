#include<iostream>
#include<algorithm>
#define SIZE 500002
using namespace std;
long long arra[SIZE] = { 0 };
long long arrb[SIZE] = { 0 };


int main()
{
	int a, b;
	cin >> a >> b;
	//a입력
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &arra[i]);
	}
	//b입력
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &arrb[i]);
	}
	//정렬
	sort(arra, arra + a);
	sort(arrb, arrb + b);
	//현재 위치
	int now_a = 0, now_b = 0, cnt = 0;
	//둘다 끝까지 갈때까지 돈다
	while (!(now_a >= a&&now_b >= b))
	{
		//둘중 하나가 끝날경우 종료
		if (arra[now_a] == 0 || arrb[now_b] == 0)break;
		//두 값이 같으면 둘 다 0으로 초기화
		if (arra[now_a] == arrb[now_b])
		{
			while (arra[now_a] == arrb[now_b])
			{
				arra[now_a++] = 0;
				cnt++;
			}
			arrb[now_b++] = 0;
		}
		else if (arra[now_a] < arrb[now_b])
		{
			now_a++;
		}
		else now_b++;
	}
	int result = 0;
	//지운 값이 원래 값과 같다. 즉, 포함되어 있을 경우 0 출력
	if (cnt == a)cout << 0 << endl;
	//아닐경우 전부 출력
	else
	{
		for (int i = 0; i < a; i++)
		{
			if (arra[i] != 0)
				result++;
		}
		cout << result << endl;
		for (int i = 0; i < a; i++)
		{
			if (arra[i] != 0)
				printf("%d ", arra[i]);
		}
	}
}