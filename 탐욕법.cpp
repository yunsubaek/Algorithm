//#include<iostream>
//#define SIZE 1002
//using namespace std;
//int arr[SIZE][SIZE] = { 0 };
//
//int main()
//{
//	int r, c;
//	cin >> r >> c;
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	//���� Ȧ��, ¦�� ����
//	if (r % 2 == 1)
//	{
//		for (int j = 0; j < r / 2; j++)
//		{
//			for (int i = 1; i < c; i++)
//				printf("R");
//			printf("D");
//			for (int i = 1; i < c; i++)
//				printf("L");
//			printf("D");
//		}
//		for (int i = 1; i < c; i++)
//			printf("R");
//	}
//	//���� ¦��, Ȧ�� Ȧ��
//	else if (c % 2 == 1)
//	{
//		for (int j = 0; j < c / 2; j++)
//		{
//			for (int i = 1; i < r; i++)
//				printf("D");
//			printf("R");
//			for (int i = 1; i < r; i++)
//				printf("U");
//			printf("R");
//		}
//		for (int i = 1; i < r; i++)
//			printf("D");
//	}
//	//�� �� ¦��. �̰� ������..
//	else
//	{
//
//	}
//}
#include<iostream>
#define SIZE 10002
using namespace std;

int main()
{
	int n, sum = 0, minus_cnt = 0, plus_cnt = 0, arr[SIZE] = { 0 };
	int zero = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] > 0)plus_cnt++;
		else if (arr[i] == 0) zero ++;
		else minus_cnt++;
	}

	//bubble sort - timelimit�� ��������
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			int temp;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	//������ ������ ����� ������ ����.
	//����� ������ ¦���̸� �� ���� �����Ѱſ���. Ȧ���̸� ������ �ϳ��� �׳� ����. 1�� ���� �ʴ� ���� ����.
	//������ ������ ¦���̸� �� ���� �����Ѱſ���. Ȧ���̸� ������ �ϳ��� �׳� ��. Ȥ�� 0�� ������ 0�̶� ����.
	
	//5				5
	//1 1 1 1 1		1 0 1 0 1      �տ��� 5 �ڿ��� 3���;� �ϴµ� 3,1 ����..������

	//����� ���.
	if (plus_cnt % 2 == 0 && arr[minus_cnt + zero] != 1)
	{
		for (int i = plus_cnt + minus_cnt + zero - 1; i > minus_cnt; i -= 2)
		{
			sum += arr[i] * arr[i - 1];
		}
	}
	else
	{
		for (int i = plus_cnt + minus_cnt + zero - 1; i > 1 + minus_cnt + zero; i -= 2)
		{
			sum += arr[i] * arr[i - 1];
		}
		if(plus_cnt % 2 == 0) sum+= arr[minus_cnt +1 + zero];
		sum += arr[minus_cnt + 1 - 1 + zero];
	}
	//������ ���
	if (minus_cnt % 2 == 0)
	{
		for (int i = 0; i < minus_cnt + zero - 1; i += 2)
		{
			sum += arr[i] * arr[i + 1];
		}
	}
	else
	{
		for (int i = 0; i < minus_cnt + zero - 1; i += 2)
		{
			sum += arr[i] * arr[i + 1];
		}
		if (zero == 0) sum += arr[minus_cnt - 1];
	}
	cout << sum << endl;
}