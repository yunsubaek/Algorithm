//https://www.acmicpc.net/problem/1700
//��Ƽ�� �����층
#include<iostream>
#define SIZE 102
using namespace std;
//arr=�Է°� ���� �迭,temp=�ܼ�Ʈ ���� ����.
int arr[SIZE], temp[SIZE];

int main()
{
	//n=�ܼ�Ʈ ���۰���,k=�Է� ����,cnt=���� �ܼ�Ʈ ����,z=�ܼ�Ʈ ������ ���� �ε���,result=���� ����.
	int n, k, cnt = 0, z = -1, result = 0, v = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < k; i++)
	{
		//�ִ³� ī��Ʈ�� ���� ������ ���� �� �׳� ����
		if (n > cnt)
		{
			//���۲������� ���� ���� ������ �߰�
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
		//���� ����ŭ á�µ� �� ���� ���
		else
		{
			//�������� �ִ��� üũ
			bool flag = 0;
			//���ۿ� �����ִ� ���� ���
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
			//�ִ³��̸� ����
			if (flag) continue;
			//���³��̸� ����� ã��(���� �ִ³��߿� ���� ���߿� ���� ����)
			else
			{
				//�������� �������� �ִ��� üũ.������� ���³��� �� ������ �׾�ߵ�
				bool chk_ = 0, end = 0;
				//���� ������ŭ ���鼭 ������ ã�ƾ���..��
				for (int j = 0; j < n; j++)
				{
					chk_ = 0, num = 0;
					//ù ��° ���۳���� ������ ���۳���� ��. ���籸�� ��������� ����
					for (int l = v; l <= k; l++)
					{
						//������ ���µ� �������� ������ ���
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