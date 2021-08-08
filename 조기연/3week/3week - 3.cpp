#include <iostream>
using namespace std;

int sales[100000] = { 0 };

int main(void)
{
	int n, k;	// n: 영업일 k: 매출측정 일수
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >> sales[i];
	}

	int max = 0;
	for (int i = 0; i < n - k; i++)
	{
		int sum = 0;
		for (int j = i; j < i + k; j++)
		{
			sum += sales[j];
		}

		if (sum > max)
			max = sum;
	}

	cout << max;

	return 0;
}