#include<iostream>
using namespace std;
//�ڵ� �� ��ȯ
template<typename T>

void myswap(T &a,T &b) 
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 3;
	int b = 4;
	myswap(a, b);
	cout << a << '/' << b;
}