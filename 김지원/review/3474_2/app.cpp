#include <bits/stdc++.h>
using namespace std;
int t, n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int a=0,b=0;
        for(int j=2; j<=n; j*=2){
            a+=n/j;
        }
        for(int j=5; j<=n; j*=5){
            b+=n/j;
        }
        cout << min(a,b)<<"\n";
    }
    return 0;
}