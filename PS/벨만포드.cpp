//#include<iostream>
//#define SIZE 102
//#define min_(a,b) (a>b?b:a)
//using namespace std;
//int arr[SIZE][SIZE] = { 0 };
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			arr[i][j] = n + 1;
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		arr[a][b] = 1;
//		arr[b][a] = 1;
//	}
//
//	for (int k = 1; k <= n; k++)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (arr[i][j] > arr[i][k] + arr[k][j])
//					arr[i][j] = arr[i][k] + arr[k][j];
//			}
//		}
//	}
//	cout << 123 << endl;
//}
#include<iostream>
#define SIZE 1000002
using namespace std;
int start[SIZE] = { 0 };
int finish[SIZE] = { 0 };

void quick_sort(int *arr, int left, int right)
{
	int i, j;
	int pivot = arr[left];
	if (left < right)
	{
		i = left;
		j = right + 1; //do while문경우 --연산먼저하므로 index를 1초과한값으로 시작
		while (i <= j)
		{
			while (arr[++i] < pivot); //내림차순을 원할경우 <를 >로
			while (arr[--j] > pivot); //오름차순을 원할경우 >를 <로
			if (i<j) // 엇갈리지않으면 두 요소를 스왑
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			else //찾은 두소요가 겹치거나 엇갈리면 한바퀴 끝
				break;
		}
		// j위치 요소를 기준이 되었던 pivot 과 Swap
		int temp = arr[j];
		arr[j] = arr[left];
		arr[left] = temp;
		//Swap ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
		quick_sort(arr, left, j - 1); // 가운데가 된 pivot을 중심으로 왼쪽 영역 재귀
		quick_sort(arr, j + 1, right);// 가운데가 된 pivot을 중심으로 오른쪽 영역 재귀
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		start[i] = a;
		finish[i] = b;
	}
	int cnt = 0, max = 0;
	//sort
	quick_sort(start, 0, n-1);
	quick_sort(finish, 0, n-1);

	int now_f = 0;

	for (int i = 0; i < n; i++)
	{
		cnt++;
		if (start[i] >= finish[now_f])
		{
			now_f++;
			cnt--;
		}
		if (max < cnt)max = cnt;
	}
	cout << max << endl;
}