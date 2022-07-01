#include <bits/stdc++.h>
using namespace std;
int n,m=1;
int main(){
    cin >> n;
    while(true){
        m++;
        if(to_string(m).find("666")!=string::npos) n--;
        if(n==0) break;
    }
    cout << m<<"\n";
    return 0;
}