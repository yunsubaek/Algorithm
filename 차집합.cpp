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
	//a�Է�
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &arra[i]);
	}
	//b�Է�
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &arrb[i]);
	}
	//����
	sort(arra, arra + a);
	sort(arrb, arrb + b);
	//���� ��ġ
	int now_a = 0, now_b = 0, cnt = 0;
	//�Ѵ� ������ �������� ����
	while (!(now_a >= a&&now_b >= b))
	{
		//���� �ϳ��� ������� ����
		if (arra[now_a] == 0 || arrb[now_b] == 0)break;
		//�� ���� ������ �� �� 0���� �ʱ�ȭ
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
	//���� ���� ���� ���� ����. ��, ���ԵǾ� ���� ��� 0 ���
	if (cnt == a)cout << 0 << endl;
	//�ƴҰ�� ���� ���
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