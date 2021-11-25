#include <iostream>
#include <vector>

using namespace std;

void solution() {
	vector<char> left;
	vector<char> right;

	string ps;
	cin >> ps;

	for (int i = 0; i < ps.length(); i++) {
		if (ps[i] == ')')
			right.push_back(ps[i]);
		else
			left.push_back(ps[i]);

		if (right.size() > left.size()) {
			cout << "NO" << endl;
			return;
		}
	}

	if (left.size() == right.size())
		cout << "YES";
	else
		cout << "NO";

	cout << endl;
}

int main(void) {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		solution();
	}

	return 0;
}