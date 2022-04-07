#include <bits/stdc++.h>

using namespace std;

string s="";

int main() {
    cin >> s;
    for(int i=97; i<=122;i++){
        int cnt=0;
        for(int it : s){
            if(it==i){
                cnt++;
            }
        }
        cout << cnt << " ";
    }
}