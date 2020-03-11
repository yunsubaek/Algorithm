////https://www.acmicpc.net/problem/1655
////����� ���ؿ�
////����..
//#include <functional>
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	priority_queue<int> l;
//	priority_queue<int, vector<int>, greater<int>> r;
//
//	while (n--)
//	{
//		int x;
//		scanf("%d", &x);
//
//		if (l.empty() || r.empty())
//			l.push(x);
//		else
//		{
//			if (x <= l.top())
//				l.push(x);
//			else
//				r.push(x);
//
//		}
//
//		while (!(l.size() == r.size() || l.size() == r.size() + 1))
//		{
//			if (l.size() > r.size())
//			{
//				r.push(l.top());
//				l.pop();
//			}
//			else
//			{
//				l.push(r.top());
//				r.pop();
//			}
//		}
//		printf("%d\n", l.top());
//	}
//	return 0;
//}
 /*
 �ڽź��� ���� ���� ���ʿ� �ְ�, ū ���� �����ʿ� �ִ´�. �켱���� ť�� ���� �ּ���,�ִ����� �ξ� ���а���.
 ������, �ε����� -10,000~10,000�̶�� ���� �����Ͽ� �迭�� �̿��Ͽ� �湮üũ�� �Ѵ�.
 (�Է¹��� �� +10,000�� �����Ͽ� �ش� �ε����� ���� 1�������� Ȯ��.
 */
//����.. �ٽ� Ǯ��
#include <cstdio>
#define SIZE 20002
#define UP(x) (x+10000)
int check[SIZE], n, left, right, mid, a;

int main()
{
	scanf("%d", &n);
	//ó�� �޴� ���� �߾Ӱ��̹Ƿ� �迭üũ �� �ٷ� ���.
	scanf("%d", &mid);
	check[UP(mid)]++;
	printf("%d\n", mid);
	for (int i = 1; i < n; i++)
	{
		//�Է¹ް� �ش� �ε��� ���� 1����.
		scanf("%d", &a);
		check[UP(a)]++;

		if (a < mid)
		{
			left++;
			while (left >= right + check[UP(mid)] || check[UP(mid)] == 0)
			{
				right += check[UP(mid)];
				mid--;
				left -= check[UP(mid)];
			}

		}
		else if (a > mid)
		{
			right++;
			while (right >= left + 1 + check[UP(mid)] || check[UP(mid)] == 0)
			{
				left += check[UP(mid)];
				mid++;
				right -= check[UP(mid)];
			}
		}
		printf("%d\n", mid);
	}
	return 0;
}