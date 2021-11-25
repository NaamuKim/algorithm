#include <iostream>
using namespace std;

int main(void) {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int date;
		cin >> date;

		int f, b;
		f = date / 100;
		b = date % 100; 

		cout << '#' << i + 1 << ' ';
		if ((f > 12 || f < 1) && (b > 12 || b < 1))
			cout << "NA";
		else if (f < 12 && b < 12)
			cout << "AMBIGUOUS";
		else if (f < 12)
			cout << "MMYY";
		else
			cout << "YYMM";

		cout << '\n';
	}

	return 0;
}