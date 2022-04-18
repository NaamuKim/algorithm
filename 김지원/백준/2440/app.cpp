#include <bits/stdc++.h>

using namespace std;

int n,t;

int main(){
    cin >>n;
    t=n;
    for(int i =0; i<n; i++){
        for(int j=0; j<t; j++){
            cout <<"*";
        }
        t--;
        cout <<"\n";
    }
}