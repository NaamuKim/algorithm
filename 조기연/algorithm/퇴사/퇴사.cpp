#include <iostream>

using namespace std;


int N;
int T[15], P[15];

int dat[15] = { 0 };
int max_P = 0;
int j = 0;

void rec(int t, int p) {
	if (t >= N) {
		if (t > N)
			p -= P[j];

		if (max_P < p)
			max_P = p;

		return;
	}

	for (int i = 0; i < N; i++) {
		if (dat[i] == 1)
			continue;

		dat[i] = 1;
		j = i;
		rec(t + T[i], p + P[i]);
		dat[i] = 0;
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	rec(0, 0);
	cout << max_P << endl;

	return 0;
}