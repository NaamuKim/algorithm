#include <iostream>
#include <vector>
using namespace std;

vector <int> set[2];
int result[30000];

int main(void) 
{
	int n;
	for (int i = 0; i < 2; i++)
	{
		cin >> n;	// 집합의 크기
		for (int j = 0; j < n; j++)
		{
			int input_num;
			cin >> input_num;

			if (j == 0)
			{
				set[i].push_back(input_num);
				continue;
			}

			int k;
			for (k = 0; k < set[i].size(); k++)
			{
				if (set[i][k] < input_num)
					continue;

				set[i].insert(set[i].begin() + k, input_num);
				break;
			}

			if (k == set[i].size())
				set[i].push_back(input_num);
		}
	}

	int set_A_idx = 0, set_B_idx = 0;
	int result_idx = 0;
	while (set_A_idx < set[0].size() && set_B_idx < set[1].size())
	{
		int set_A = set[0][set_A_idx];
		int set_B = set[1][set_B_idx];

		if (set_A == set_B) 
		{
			result[result_idx++] = set_A;
		
			set_A_idx++;
			set_B_idx++;
		}

		if (set_A > set_B)
			set_B_idx++;

		if (set_B > set_A)
			set_A_idx++;
	}
	
	for (int i = 0; i < result_idx; i++)
		cout << result[i] << ' ';

	return 0;
}