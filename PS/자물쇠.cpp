//#include<iostream>
//#include<string.h>
//#define SIZE 102
//using namespace std;
//int n, dp[SIZE][10];
//char pass[SIZE], result[SIZE];
//
////i=디스크,num=디스크 숫자,저장값=돌린 횟수(돌린 횟수가 길이보다 같거나 길면 리턴)
//int chk(int i,int num)
//{
//	//현재 디스크와 비교 디스크가 같을 경우 종료.
//	if (strcmp(pass, result))return 1;
//	if (dp[i][num] != -1)return dp[i][num];
//	int minus = 0, plus = 0;
//	for (int j = 0; j < 3; j++)
//	{
//		//3개 디스크를 확인하면서 작은경우 큰경우셈.
//		int cnt[3] = { 0 };
//		if (pass[i + j] < result[i + j]) cnt[j]--;
//		else if (pass[i + j]>result[i + j]) cnt[j]++;
//	}
//}
//
///*
//자물쇠 = n개의 디스크로 구성, 디스크는 0~9의 숫자로 구성.
////dp[SIZE][10] => n*10으로 디피. -1로 초기화하고 시작. 0일수도 있으니까.
//자물쇠는 한 번에 최대 3칸을 돌릴 수 있다.(시계or반시계 방향)
//자물쇠는 세 개의 인접한 디스크를 한 번에 돌릴 수 있다.(0,9는 인접-환형구조)
//디스크의 숫자는 0~9
//암호를 해제하기까지의 최소 횟수는?(pass->result)
//1<=n<=100
//*/
//
//int main()
//{
//	cin >> n >> pass >> result;
//	memset(dp, -1, sizeof(dp));
//	cout << chk(0,0);
//}
