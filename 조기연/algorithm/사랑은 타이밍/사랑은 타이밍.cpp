#include <iostream>
using namespace std;


int main(void) {

	int t;
	cin >> t;

	int D[10], H[10], M[10];
	for (int i = 0; i < t; i++) {
		cin >> D[i] >> H[i] >> M[i];
	}

	for (int i = 0; i < t; i++) {
		int date = 11 * 1440 + 11 * 60 + 11;
		int bram = D[i] * 1440 + H[i] * 60 + M[i];
		
		cout << '#' << i + 1 << ' ';
		if (bram < date)
			cout << -1;
		else
			cout << bram - date << endl;
	}

	return 0;
}