#include <iostream>
using namespace std;
int main(){
	int i_size = 0;
	int i_num[100] = {0};
	int i_cal, i_tot, i_max, i_result =0;
	cin >> i_size;
	cin.ignore();
	for(int i = 0; i < i_size; i++)
		cin >> i_num[i];

	for(int i= 0; i< i_size; i++){
		i_cal = i_num[i];
		//for(int j = 0; j < sizeof(i_sum); j++){
			while(i_cal != 0){
				i_tot += i_cal % 10;
				i_cal = i_cal / 10;
			}
				if(i_tot >= i_max){
					if(i_tot == i_max){
						if(i_result < i_num[i])
							i_result = i_num[i];
					}
					else{
					i_max = i_tot;
					i_result = i_num[i];
					}
					//cout << i_max << "\t";
				}	
				i_tot = 0;
		//cout << i_result << endl;
	}
	cout << i_result << endl;
}
