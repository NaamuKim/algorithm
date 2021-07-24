#include <iostream>
#include <string>
#include <math.h>
using namespace std;


bool isPrime(int n)
{
	if (n == 1)
		return false;

	int sqrt_num = sqrt(n);
	for (int i = 2; i <= sqrt_num; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		string str_num = to_string(num);

		int reverse_num = 0;
		for (int i = 0; i < str_num.length(); i++)
		{
			reverse_num *= 10;
			reverse_num += num % 10;
			num /= 10;
		}

		if (isPrime(reverse_num))
			cout << reverse_num << ' ';
	}

	return 0;
}