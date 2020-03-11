#include<iostream>
#define SIZE 200002
using namespace std;

void swap(int *arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int *arr, int left, int right) {
	int temp = arr[left];
	arr[left] = arr[(left + right) / 2];
	arr[(left + right) / 2] = temp;

	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {

		while (low <= right && arr[low] <= pivot)
			low++;
		while (left + 1 <= high && pivot <= arr[high])
			high--;

		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return high;
}

void quick_sort(int *arr, int left, int right) {
	if (left <= right) {
		int pivot = partition(arr, left, right);

		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}

int main()
{
	int n, c, min = -1, max = 0, mid = 0, arr[SIZE] = { 0 }, cnt = 1;
	cin >> n >> c;

	//input
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//sort
	quick_sort(arr, 0, n - 1);

	max = arr[n - 1] - arr[0];

	while (min + 1 < max)
	{
		mid = (max + min) / 2;
		int minus = arr[0];
		cnt = 1;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] - minus >= mid)
			{
				cnt++;
				minus = arr[i];
			}
		}
		if (cnt < c)
			max = mid;
		else
			min = mid;
	}
	cout << min << endl;
}