#include <iostream>
using namespace std;

int main(void) {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		int time = (a + b) % 24;

		cout << '#' << i + 1 << ' ';
		cout << time << endl;
	}

	return 0;
}