#include <iostream>

using namespace std;

int N;
string student_Number[1000];

int num = 0;
void rec(int k) {
	int len = student_Number[0].length();

	if (k == len + 1)
		return;

	int flag = 1;
	for (int i = 0; i < N; i++)
	{
		string str_1 = "";
		for (int l = len - k; l < len; l++)
		{
			str_1 += student_Number[i][l];
		}

		for(int j = 0; j < N; j++)
		{
			if (i == j)
				continue;

			string str_2 = "";
			for (int l = len - k; l < len; l++)
			{
				str_2 += student_Number[j][l];
			}

			if (str_1 == str_2)
			{
				flag = 0;
				rec(k + 1);
				break;
			}
		}

		if (flag == 0)
			break;
	}

	if (flag == 1)
		num = k;
}


int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> student_Number[i];
	}

	rec(1);

	printf("%d", num);

	return 0;
}