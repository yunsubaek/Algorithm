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
		j = right + 1; //do while����� --��������ϹǷ� index�� 1�ʰ��Ѱ����� ����
		while (i <= j)
		{
			while (arr[++i] < pivot); //���������� ���Ұ�� <�� >��
			while (arr[--j] > pivot); //���������� ���Ұ�� >�� <��
			if (i<j) // �������������� �� ��Ҹ� ����
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			else //ã�� �μҿ䰡 ��ġ�ų� �������� �ѹ��� ��
				break;
		}
		// j��ġ ��Ҹ� ������ �Ǿ��� pivot �� Swap
		int temp = arr[j];
		arr[j] = arr[left];
		arr[left] = temp;
		//Swap �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
		quick_sort(arr, left, j - 1); // ����� �� pivot�� �߽����� ���� ���� ���
		quick_sort(arr, j + 1, right);// ����� �� pivot�� �߽����� ������ ���� ���
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