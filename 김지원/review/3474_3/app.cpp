#include <bits/stdc++.h>
using namespace std;
int t, n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int cnt2=0, cnt5=0;
        for(int i=2; i<=n; i*=2){
            cnt2+=n/i;
        }
        for(int i=5; i<=n; i*=5){
            cnt5+=n/i;
        }
        cout <<min(cnt2,cnt5)<<'\n';
    }
    return 0;
}