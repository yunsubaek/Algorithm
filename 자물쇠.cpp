//#include<iostream>
//#include<string.h>
//#define SIZE 102
//using namespace std;
//int n, dp[SIZE][10];
//char pass[SIZE], result[SIZE];
//
////i=��ũ,num=��ũ ����,���尪=���� Ƚ��(���� Ƚ���� ���̺��� ���ų� ��� ����)
//int chk(int i,int num)
//{
//	//���� ��ũ�� �� ��ũ�� ���� ��� ����.
//	if (strcmp(pass, result))return 1;
//	if (dp[i][num] != -1)return dp[i][num];
//	int minus = 0, plus = 0;
//	for (int j = 0; j < 3; j++)
//	{
//		//3�� ��ũ�� Ȯ���ϸ鼭 ������� ū����.
//		int cnt[3] = { 0 };
//		if (pass[i + j] < result[i + j]) cnt[j]--;
//		else if (pass[i + j]>result[i + j]) cnt[j]++;
//	}
//}
//
///*
//�ڹ��� = n���� ��ũ�� ����, ��ũ�� 0~9�� ���ڷ� ����.
////dp[SIZE][10] => n*10���� ����. -1�� �ʱ�ȭ�ϰ� ����. 0�ϼ��� �����ϱ�.
//�ڹ���� �� ���� �ִ� 3ĭ�� ���� �� �ִ�.(�ð�or�ݽð� ����)
//�ڹ���� �� ���� ������ ��ũ�� �� ���� ���� �� �ִ�.(0,9�� ����-ȯ������)
//��ũ�� ���ڴ� 0~9
//��ȣ�� �����ϱ������ �ּ� Ƚ����?(pass->result)
//1<=n<=100
//*/
//
//int main()
//{
//	cin >> n >> pass >> result;
//	memset(dp, -1, sizeof(dp));
//	cout << chk(0,0);
//}
