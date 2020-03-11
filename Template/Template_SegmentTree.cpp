#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;
const int inf_ = 987654321;

template<typename T>
T min_(T &a, T &b)
{
	return a < b ? a : b;
}

template<typename T>
class sg_tree
{
public:
	int n;
	vector<T> range;
	sg_tree(const vector<T> &arr)
	{
		n = arr.size();
		range.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	T init(const vector<T> &arr, int left, int right, int node)
	{
		if (left == right)return range[node] = arr[left];
		int mid = (left + right) / 2;
		T left_sum = init(arr, left, mid, node * 2);
		T right_sum = init(arr, mid + 1, right, node * 2 + 1);
		return range[node] = left_sum + right_sum;
		//여기서는 최소값이 아님
	}
	T query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left)return 0;
		else if (left <= nodeLeft && nodeRight <= right)return range[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}
	T query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}
	T update(int index, T newValue, int node, int nodeLeft, int nodeRight)
	{
		if (index < nodeLeft || nodeRight < index)return range[node];
		if (nodeLeft == nodeRight) return range[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return range[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	}
	T update(int index, T newValue)
	{
		return update(index, newValue, 1, 0, n - 1);
	}
};

const int size_ = 1000002;
int n, m, k;
vector<ll> arr(size_);

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
	{
		ll a;
		scanf("%lld", &a);
		arr[i] = a;
	}
	sg_tree<ll> sg(arr);
	for (int i = 0; i < m + k; ++i)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		if (a == 1)
		{
			sg.update(b-1, c);
		}
		else
		{
			printf("%lld\n", sg.query(b - 1, c - 1));
		}
	}
	return 0;
}
