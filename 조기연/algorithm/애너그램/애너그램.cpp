#include <iostream>

using namespace std;

bool solution() {
	string a, b;
	cin >> a >> b;

	int dat_a[26] = { 0 };
	int dat_b[26] = { 0 };

	if (a.length() != b.length())
		return false;

	for (int i = 0; i < a.length(); i++) {
		dat_a[a[i] - 'a'] = 1;
		dat_b[b[i] - 'a'] = 1;
	}

	for (int i = 0; i < 26; i++) {

		if (dat_a[i] != dat_b[i])
			return false;
	}

	return true;
}

int main(void) {

	if (solution())
		cout << "yes";
	else
		cout << "no";
}