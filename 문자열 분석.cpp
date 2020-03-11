#include<iostream>
using namespace std;

int main()
{
	char arr[102] = { 0 };
	while (1)
	{
		cin.getline(arr, 102);
		{
			if (arr[0] == '\0')return 0;
			int so = 0, dae = 0, su = 0, space = 0;
			for (int i = 0; arr[i] != '\0'; i++)
			{
				if (arr[i] >= 'A' && arr[i] <= 'Z')dae++;
				if (arr[i] >= 'a' && arr[i] <= 'z')so++;
				if (arr[i] >= '0' && arr[i] <= '9')su++;
				if (arr[i] == ' ')space++;
			}
			cout << so << ' ' << dae << ' ' << su << ' ' << space << endl;
			so = 0, dae = 0, su = 0, space = 0;
		}
	}
}