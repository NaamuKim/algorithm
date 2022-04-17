#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
ll ret;

int main(){
    cin >> n;
    ret= 666;
    for(;; ret++){
        if(to_string(ret).find("666")!=string::npos) n--;
        if(n==0) break;
    }
    cout << ret << "\n";
    return 0;
}