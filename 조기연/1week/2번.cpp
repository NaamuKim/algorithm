#include <iostream>
using namespace std;

int n;
int arr[50][50] = { 0 };

int sum()
{
	int max = 0;
	int sum_Row = 0, sum_Col = 0, sum_Dig1 = 0, sum_Dig2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum_Dig1 += arr[i][i];
		sum_Dig2 += arr[i][4 - i];

		for (int j = 0; j < n; j++)
		{
			sum_Row += arr[i][j];
			sum_Col += arr[j][i];
		}

		if (sum_Row > max)
			max = sum_Row;

		if (sum_Col > max)
			max = sum_Col;

		sum_Row = 0;
		sum_Col = 0;
	}

	if (sum_Dig1 > max)
		max = sum_Dig1;

	if (sum_Dig2 > max)
		max = sum_Dig2;

	return max;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int max = sum();
	cout << max;

	return 0;
}