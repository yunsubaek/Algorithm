////https://www.acmicpc.net/problem/1655
////가운데를 말해요
////베낌..
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
 자신보다 작은 값은 왼쪽에 넣고, 큰 값은 오른쪽에 넣는다. 우선순위 큐로 각각 최소힙,최대힙을 두어 구분가능.
 하지만, 인덱스가 -10,000~10,000이라는 점에 착안하여 배열을 이용하여 방문체크를 한다.
 (입력받은 값 +10,000을 저장하여 해당 인덱스의 값을 1증가시켜 확인.
 */
//베낌.. 다시 풀어
#include <cstdio>
#define SIZE 20002
#define UP(x) (x+10000)
int check[SIZE], n, left, right, mid, a;

int main()
{
	scanf("%d", &n);
	//처음 받는 값은 중앙값이므로 배열체크 및 바로 출력.
	scanf("%d", &mid);
	check[UP(mid)]++;
	printf("%d\n", mid);
	for (int i = 1; i < n; i++)
	{
		//입력받고 해당 인덱스 값을 1증가.
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