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
//	//행이 홀수, 짝은 노상관
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
//	//행은 짝수, 홀은 홀수
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
//	//둘 다 짝수. 이게 문제임..
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

	//bubble sort - timelimit시 수정ㄱㄱ
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
	//음수의 갯수와 양수의 갯수를 센다.
	//양수의 갯수가 짝수이면 다 곱해 정렬한거에서. 홀수이면 나머지 하나는 그냥 더해. 1은 묶지 않는 것이 좋음.
	//음수의 갯수가 짝수이면 다 곱해 정렬한거에서. 홀수이면 나머지 하나는 그냥 둬. 혹시 0이 있으면 0이랑 곱해.
	
	//5				5
	//1 1 1 1 1		1 0 1 0 1      앞에껀 5 뒤에껀 3나와야 하는데 3,1 나옴..수정해

	//양수일 경우.
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
	//음수일 경우
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