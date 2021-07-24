#include <iostream>
using namespace std;

int g, n, quo;
int idx = 0;
int arr[100] = { 0 };
int result[100] = { 0 };

int getMax()
{
	int max = -1000;
	for (int i = 0; i < g; i++)
	{
		if (idx + i >= 100)
			break;

		if (arr[idx + i] > max)
			max = arr[idx + i];
	}
	idx += g;

	return max;
}

int main(void)
{
	
	cin >> n >> g;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	quo = n / g;
	if (n % g != 0)
		quo++;

	for (int i = 0; i < quo; i++)
	{
		result[i] = getMax();
	}

	for (int i = 0; i < quo; i++)
	{
		cout << result[i] << ' ';
	}

	return 0;
}