#include <iostream>
using namespace std;

int n, m;
int card[100];

int path[3] = { 0 };
int max_sum = 0;

void rec(int lev, int sum)
{
	if (lev == 3)
	{
		int max_n = m - max_sum;
		int n = m - sum;
		if (max_n > n && n >= 0)
			max_sum = sum;

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if ((lev > 0 && path[lev - 1] == i) || (lev > 1 && path[lev - 2] == i))
			continue;

		path[lev] = i;
		rec(lev + 1, sum + card[i]);
		path[lev] = i;
	}
}

int main(void) {

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}

	rec(0, 0);

	cout << max_sum;

	return 0;
}