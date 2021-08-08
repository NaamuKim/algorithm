#include <iostream>
using namespace std;

int stu_1[5] = { 1,2,3,4,5 };
int stu_2[8] = { 2,1,2,3,2,4,2,5 };
int stu_3[10] = { 3,3,1,1,2,2,4,4,5,5 };
int answer[100];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> answer[i];
	}

	int cnt[3] = { 0 };
	for (int i = 0; i < n; i++)
	{
		if (stu_1[i % 5] == answer[i])
			cnt[0]++;

		if (stu_2[i % 8] == answer[i])
			cnt[1]++;

		if (stu_3[i % 10] == answer[i])
			cnt[2]++;
	}

	if (cnt[0] == cnt[1] && cnt[0] == cnt[2])
		cout << "모든 사람이 " << cnt[0] << "문제씩을 맞혔습니다.";
	else 
	{
		for (int i = 0; i < 3; i++)
		{
			if (cnt[i] == 0)
				cout << "수포자 " << i + 1 << "은 모든 문제를 틀렸습니다." << '\n';
			else if (cnt[i] == n)
				cout << "수포자 " << i + 1 << "은 모든 문제를 맞혔습니다." << '\n';
			else
				cout << "수포자 " << i + 1 << "은 " << cnt[i] << "문제를 맞췄습니다." << '\n';
		}

		int max_idx = 0;
		for (int i = 0; i < 3; i++)
		{
			if (cnt[i] > cnt[max_idx])
				max_idx = i;
		}

		cout << "따라서 가장 문제를 많이 맞힌 사람은 수포자 " << max_idx + 1 << "입니다." << '\n';
	}


	return 0;
}