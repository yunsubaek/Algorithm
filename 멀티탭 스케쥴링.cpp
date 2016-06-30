//https://www.acmicpc.net/problem/1700
//멀티탭 스케쥴링
#include<iostream>
#define SIZE 102
using namespace std;
//arr=입력값 저장 배열,temp=콘센트 저장 정보.
int arr[SIZE], temp[SIZE];

int main()
{
	//n=콘센트 구멍갯수,k=입력 갯수,cnt=꼽힌 콘센트 갯수,z=콘센트 저장을 위한 인덱스,result=뽑은 갯수.
	int n, k, cnt = 0, z = -1, result = 0, v = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < k; i++)
	{
		//넣는놈 카운트가 구멍 수보다 적을 때 그냥 넣음
		if (n > cnt)
		{
			//구멍꼽힌곳에 넣을 값이 없으면 추가
			bool flag = 0;
			for (int j = 0; j < z + 1; j++)
			{
				if (temp[j] == arr[i])
				{
					flag = 1;
					arr[i] = 0;
					v++;
					//temp[j] = 0;
					break;
				}
			}
			if (!flag)
			{
				temp[++z] = arr[i];
				arr[i] = 0;
				v++;
				cnt++;
			}
		}
		//구멍 수만큼 찼는데 더 들어올 경우
		else
		{
			//같은놈이 있는지 체크
			bool flag = 0;
			//구멍에 꽂혀있는 값일 경우
			for (int j = 0; j < n; j++)
			{
				if (temp[j] == arr[i])
				{
					flag = 1;
					arr[i] = 0;
					v++;
					//temp[j] = 0;
					break;
				}
			}
			int max = 0, max_idx = 0, num = 0;
			//있는놈이면 냅둠
			if (flag) continue;
			//없는놈이면 지울놈 찾자(지금 있는놈중에 가장 나중에 쓸놈 지워)
			else
			{
				//다음번에 같은놈이 있는지 체크.없을경우 없는놈이 걍 무조건 죽어야됨
				bool chk_ = 0, end = 0;
				//구멍 갯수만큼 돌면서 다음놈 찾아야함..ㅎ
				for (int j = 0; j < n; j++)
				{
					chk_ = 0, num = 0;
					//첫 번째 구멍놈부터 마지막 구멍놈까지 비교. 현재구멍 다음놈부터 비교함
					for (int l = v; l <= k; l++)
					{
						//끝까지 갔는데 같은놈을 못만난 경우
						if (l == k && chk_ == 0)
						{
							max_idx = j;
							end = 1;
							break;
						}
						if (temp[j] != arr[l])  num++;
						else if (temp[j] == arr[l])
						{
							if (num > max)
							{
								max = num;
								max_idx = j;
							}
							chk_ = 1;
							break;
						}
					}
					if (end)break;
				}
				temp[max_idx] = arr[i];
				arr[i] = 0;
				v++;
				result++;
			}
		}
	}
	cout << result;
}