#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int temp[11] = { 1 };
//�ּ� cnt, sum
long long c = 0, s = 0;
/*
�Ҽ����� x(������ ��)�� ���ؼ� ������ ���� ����� cnt�� ���Ѵ�.(�ּ�)
�ֻ����� ������ �� ��ŭ�� ���°��� �ּ�.
����,�Ҽ���(a,b)�� �� cnt�� ���� sum�� ����� ���� �ּ� ������ dp(���)�� ���� ��.
=>�κ�����(4.01�� ���� ��츦 ������ ����. �� �κ��� ó���ϴ� ���� �߰��ؾ� �Ұ�. 01�� ��� %d�� �ޱ� ������ 1�� ó��)
*/

int d_len(int a)
{
	int i = 1;
	while (a > 9)
	{
		i++;
		a /= 10;
	}
	return i;
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 1; i < 10; i++)
	{
		temp[i] = temp[i - 1] * 10;
	}

	for (int itr = 0; itr < tc; itr++)
	{
		int a, b = 0;
		int arr[5] = { 0 };
		char zz[10] = { 0 };
		//�Է� �� �Ҽ��� ó��
		scanf("%d.", &a);
		scanf("%s", &zz);
		int z_cnt = 0;
		for (int i = 0; i < strlen(zz); i++)
		{
			if (zz[i] == '0')z_cnt++;
			else b += (zz[i] - '0')*(pow(10, strlen(zz) - z_cnt - 1));
		}
		int m;
		if (b == 0)m = a;
		else m = a + 1;

		if (b == 0)arr[a - 1]++;
		else
		{
			for (int i = 0; i < 11; i++)
			{
				if (temp[i] % b == 0)
				{
					c = temp[i] / b;
					break;
				}
			}
			int b_len = d_len(b);
			if (z_cnt != 0)c *= z_cnt;
			s = (a*c) + (b*c) / pow(10, b_len);

			bool flag = 0;
			//sum,cnt�� �̿��Ͽ� �ּ� cnt�� �̿��Ͽ� ���� �� �ִ� sum�� ����.
			if (m == 5)
				for (int i_5 = a - 1; i_5 >= 0; i_5--)
				{
					for (int i_4 = a - 1; i_4 >= 0; i_4--)
					{
						for (int i_3 = a - 1; i_3 >= 0; i_3--)
						{
							for (int i_2 = a - 1; i_2 >= 0; i_2--)
							{
								for (int i_1 = a - 1; i_1 >= 0; i_1--)
								{
									int sum = i_5 * 5 + i_4 * 4 + i_3 * 3 + i_2 * 2 + i_1;
									int cnt = i_5 + i_4 + i_3 + i_2 + i_1;
									if (sum == s&&cnt == c)
									{
										arr[0] = i_1;
										arr[1] = i_2;
										arr[2] = i_3;
										arr[3] = i_4;
										arr[4] = i_5;
										flag = 1;
										break;
									}
								}
								if (flag)break;
							}
							if (flag)break;
						}
						if (flag)break;
					}
					if (flag)break;
				}

			else if (m == 4)
				for (int i_4 = a - 1; i_4 >= 0; i_4--)
				{
					for (int i_3 = a - 1; i_3 >= 0; i_3--)
					{
						for (int i_2 = a - 1; i_2 >= 0; i_2--)
						{
							for (int i_1 = a - 1; i_1 >= 0; i_1--)
							{
								int sum = i_4 * 4 + i_3 * 3 + i_2 * 2 + i_1;
								int cnt = i_4 + i_3 + i_2 + i_1;
								if (sum == s&&cnt == c)
								{
									arr[0] = i_1;
									arr[1] = i_2;
									arr[2] = i_3;
									arr[3] = i_4;
									flag = 1;
									break;
								}
							}
							if (flag)break;
						}
						if (flag)break;
					}
					if (flag)break;
				}
			else if (m == 3)
				for (int i_3 = a - 1; i_3 >= 0; i_3--)
				{
					for (int i_2 = a - 1; i_2 >= 0; i_2--)
					{
						for (int i_1 = a - 1; i_1 >= 0; i_1--) {
							int sum = i_3 * 3 + i_2 * 2 + i_1;
							int cnt = i_3 + i_2 + i_1;
							if (sum == s&&cnt == c)
							{
								arr[0] = i_1;
								arr[1] = i_2;
								arr[2] = i_3;
								flag = 1;
								break;
							}
						}
						if (flag)break;
					}
					if (flag)break;
				}

			else if (m == 2)
				for (int i_2 = a - 1; i_2 >= 0; i_2--)
				{
					for (int i_1 = a - 1; i_1 >= 0; i_1--)
					{
						int sum = i_2 * 2 + i_1;
						int cnt = i_2 + i_1;
						if (sum == s&&cnt == c)
						{
							arr[0] = i_1;
							arr[1] = i_2;
							flag = 1;
							break;
						}
					}
					if (flag)break;
				}

			else if (m == 1)
				for (int i_1 = a - 1; i_1 >= 0; i_1--)
				{
					int sum = i_1;
					int cnt = i_1;
					if (sum == s&&cnt == c)
					{
						arr[0] = i_1;
						flag = 1;
						break;
					}
				}

		}
		//���
		printf("Case #%d\n", itr + 1);
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}