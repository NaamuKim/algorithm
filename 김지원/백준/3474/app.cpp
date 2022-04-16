#include <bits/stdc++.h>

using namespace std;

int t, num;
int cnt2, cnt5;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i =0; i<t; i++){
        cin >> num;
        cnt2 = 0;
        cnt5 = 0;
        for(int j= 2; j<=num; j*=2){
            cnt2 += num / j;
        }
        for(int k = 5; k<=num; k*=5){
            cnt5 += num / k;
        }
        cout << min(cnt2, cnt5) << "\n"; 
    }
    return 0;
}