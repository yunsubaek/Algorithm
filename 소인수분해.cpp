#include<iostream>
using namespace std;

int main()
{
	int n, i = 2;
	cin >> n;
	while (n)
	{
		if (n%i == 0)
		{
			printf("%d\n", i);
			n /= i;
		}
		else i++;
		if (n == 1)break;
	}
}