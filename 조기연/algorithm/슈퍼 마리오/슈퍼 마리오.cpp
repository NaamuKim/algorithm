#include <iostream>

using namespace std;


int main(void) {

	int score[10];
	for (int i = 0; i < 10; i++) {
		cin >> score[i];
	}

	int answer;
	int answer_tmp = 100;
	for (int i = 1; i <= 10; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += score[j];
		}

		int tmp;
		tmp = sum > 100 ? sum - 100 : 100 - sum;

		if (tmp < answer_tmp) {
			answer = sum;
			answer_tmp = answer > 100 ? answer - 100 : 100 - answer;
		}

		if (tmp == answer_tmp && sum > answer)
			answer = sum;
	}

	cout << answer;

	return 0;
}