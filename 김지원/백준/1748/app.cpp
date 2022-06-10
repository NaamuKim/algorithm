#include <bits/stdc++.h>
using namespace std;
int n;
long long ret;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i*=10){
        ret+=n-i+1;
    }
    cout << ret <<"\n";
    return 0;
}