#include<cstdio>
#include<vector>
using namespace std;

bool cmp(const int &a, const int &b)
{
	return a < b;
}

template<typename T>
void swap_(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
class priority_queue
{
public:
	vector<T> v;
	priority_queue()
	{
		v.push_back(0);
	}
	T max_(T a, T b)
	{
		return a > b ? a : b;
	}
	void push(T data)
	{
		v.push_back(data);
		int idx = v.size()-1;
		while (idx != 1)
		{
			if (v[idx / 2] < v[idx])
			{
				swap_(v[idx / 2], v[idx]);
			}
			idx /= 2;
		}
	}
	void pop()
	{
		int t_idx = 1;
		int idx = v.size()-1;
		swap_(v[t_idx], v[idx]);
		v.pop_back();
		idx--;
		while (t_idx*2 <= idx)
		{
			int b_idx;
			if (t_idx * 2 + 1 <= idx)
			{
				if (v[t_idx] < max_(v[t_idx * 2], v[t_idx * 2 + 1]))
				{
					T temp = max_(v[t_idx * 2], v[t_idx * 2 + 1]);
					b_idx = v[t_idx * 2] == temp ? t_idx * 2 : t_idx * 2 + 1;
				}
				else break;
			}
			else b_idx = t_idx * 2;
			if (v[t_idx] < v[b_idx])
			{
				swap_(v[t_idx], v[b_idx]);
			}
			t_idx = b_idx;
		}
	}
	T top()
	{
		if (v.empty())return -1;
		return v[1];
	}
	int size()
	{
		return v.size() - 1;
	}
	bool empty()
	{
		return v.size() == 1;
	}
};

int main()
{
	priority_queue<int> pq;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a == 0)
		{
			if (pq.empty())printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(a);
	}
	return 0;
}
