#include<iostream>
#define SIZE 102
using namespace std;
long long padovan[SIZE] = { 0,1,1,1,2 };
int main() {
	int tc;
	cin >> tc;
	for (int i = 5; i<SIZE; i++) {
		padovan[i] = padovan[i - 2] + padovan[i - 3];
	}
	for (int itr = 0; itr<tc; itr++) {
		int a;
		cin >> a;
		cout << padovan[a]<<"\n";
	}
}