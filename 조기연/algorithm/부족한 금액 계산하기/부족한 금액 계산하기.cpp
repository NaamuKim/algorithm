#include <iostream>
using namespace std;


long long solution(int price, int money, int count) {

	long long total_Price = 0;
	for (int i = 1; i <= count; i++) {
		total_Price += price * i;
	}

	long long answer = total_Price - money;

	if (answer <= 0)
		return 0;

	return answer;
}