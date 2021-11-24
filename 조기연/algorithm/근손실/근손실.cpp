#include <iostream>

using namespace std;

int N, K;
int A[8];
int dat[8] = { 0 };

int cnt = 0;
void rec(int day, int sum) {
	if (sum < 500)
		return;

	if (day == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) 
	{
		if (dat[i] == 1)
			continue;

		dat[i] = 1;
		rec(day + 1, sum + A[i] - K);
		dat[i] = 0;
	}
}

int main(void) {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	rec(1, 500);

	printf("%d", cnt);
}