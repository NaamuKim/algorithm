#include <iostream>
#include <string>
using namespace std;

int solution(int n)
{
	string str_n = to_string(n);

	int start_num = n - 9 * str_n.length();
	for (int i = start_num; i < n; i++)
	{
		int cur_num = i;
		int sum = 0;
		while (cur_num != 0)
		{
			if (sum == 0)
				sum += cur_num;

			sum += cur_num % 10;
			cur_num /= 10;
		}

		if (sum == n)
			return i;
	}

	return 0;
}

int main(void)
{
	int n;
	cin >> n;

	cout << solution(n) << endl;

	return 0;
}