//https://www.acmicpc.net/problem/1904
//01≈∏¿œ
#include<iostream>
#define SIZE 1000002
using namespace std;

int fibo[SIZE] = { 1,1 };

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i < SIZE; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2])% 15746;
	cout << fibo[n] << endl;
}