#include <bits/stdc++.h>

using namespace std;

int n,ret;
string s;

void go(int here){
    if(here == n){
        int sum =0;
    }
    a[here]=~a[here];
    go(here+1);
    a[here]=a[here];
    go(here+1);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        int value =1;
        for(int j=0; j<n; j++){
            if(s[j]=='T') a[i]|=value;
            value*=2;
        }
    }
    go(1);
    cout << ret <<"\n";
}