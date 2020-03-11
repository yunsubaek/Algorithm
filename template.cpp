#include<iostream>
using namespace std;
//자동 형 변환
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