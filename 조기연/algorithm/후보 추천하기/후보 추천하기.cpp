#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s {
	int num;
	int good_Cnt;
	int ttl;
};

bool cmp(const s& a, const s& b)
{
	if (a.num < b.num)
		return true;

	return false;
}

int main(void) {
	int n;
	cin >> n;

	int good;
	cin >> good;

	vector<s> pic;
	
	int min_Good = 1000;
	for (int i = 0; i < good; i++) {
		
		int good_Num;
		cin >> good_Num;

		int flag = 0;
		for (int j = 0; j < pic.size(); j++) {

			if (good_Num != pic[j].num)
				continue;

			flag = 1;
			pic[j].good_Cnt++;
			break;
		}

		if (flag == 1)
			continue;

		if (pic.size() < n)
			pic.push_back({ good_Num, 0 });
		else {

			int min_Idx = 0;
			for (int j = 1; j < n; j++) {

				if (pic[min_Idx].good_Cnt < pic[j].good_Cnt)
					continue;
				
				if (pic[min_Idx].good_Cnt == pic[j].good_Cnt)
					if (pic[min_Idx].ttl > pic[j].ttl)
						continue;

				min_Idx = j;
			}

			pic[min_Idx] = { good_Num, 0, 0 };
		}

		for (int j = 0; j < pic.size(); j++) {
			pic[j].ttl++;
		}
	}

	sort(pic.begin(), pic.end(), cmp);
	for (int i = 0; i < pic.size(); i++) {
		cout << pic[i].num << ' ';
	}

	return 0;
}