#include <iostream>
using namespace std;

int main(void)
{
	int n, m;	// n: 재료의 개수, m: 갑옷을 만드는데 필요한 수
	cin >> n >> m;

	int n_num[15000];
	for (int i = 0; i < n; i++)	// 각 재료의 고유한 번호 입력
	{
		cin >> n_num[i];
	}

	int cnt = 0;
	int use[15000] = { 0 };
	for (int i = 0; i < n - 1; i++)
	{
		if (use[i] == 1) 
			continue;

		for (int j = i + 1; j < n; j++)
		{
			if (use[j] == 1) 
				continue;

			int sum = n_num[i] + n_num[j];	// 두 개의 재료를 합침
			if (sum == m)	// m(갑옷을 만드는데 필요한 수)와 같으면 cnt++
			{
				cnt++;
				use[i] = use[j] = 1;	// 사용한 재료 기록
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}