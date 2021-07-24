#include <iostream>
using namespace std;

int arr[10][20];

int main(void) {
	int stu, exam;
	cin >> stu >> exam;

	for (int i = 0; i < exam; i++)
	{
		for (int j = 0; j < stu; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= stu; i++)
	{	
		int dat[20] = { 0 };
		for (int j = 0; j < exam; j++)
		{
			int flag = 0;
			for (int k = 0; k < stu; k++)
			{
				if (arr[j][k] == i)
					flag = 1;

				if (flag == 1)
					dat[k] = 1;
			}
		}

		for (int j = 0; j < stu; j++)
		{
			if (dat[j] == 0)
				cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}