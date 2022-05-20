#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    long long ret=666;
    while(true){
        if(to_string(ret).find("666")!=string::npos) n--;
        if(n==0) break;
        ret++;
    }
    cout << ret <<"\n";
    return 0;
}