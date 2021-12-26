#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> dice;

int main(void) {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp[3];
		for (int j = 0; j < 3; j++) {
			cin >> temp[j];
		}

		dice.push_back({ temp[0], temp[1], temp[2] });
	}

	int max_Reward = 0;
	for (int i = 0; i < n; i++) {
		
		int eq_Cnt = 0;
		int eq_Num;
		if (dice[i][0] == dice[i][1])
			eq_Num = dice[i][0];
			eq_Cnt++;

		if (dice[i][0] == dice[i][2]) {
			eq_Num = dice[i][0];
			eq_Cnt++;
		}

		if (dice[i][1] == dice[i][2]) {
			eq_Num = dice[i][1];
			eq_Cnt++;
		}

		int reward;
		switch (eq_Cnt) {
		
		case 1:
			reward = 1000 + (eq_Num * 100);
			break;

		case 3:
			reward = 10000 + (eq_Num * 1000);
			break;

		default:
			int max = 0;
			for (int j = 0; j < 3; j++) {
				if (dice[i][j] < max)
					continue;

				max = dice[i][j];
			}

			reward = max * 100;
		}

		if (max_Reward < reward)
			max_Reward = reward;
	}

	cout << max_Reward << endl;

	return 0;
}