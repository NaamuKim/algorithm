#include <bits/stdc++.h>

using namespace std;

int out, in, res, _max=0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    for(int i =0; i<4; i++){
        cin >> out >> in;
        res-=out;
        res+=in;
        _max=max(res,_max);
    }
    cout << _max <<"\n";
    return 0;
}