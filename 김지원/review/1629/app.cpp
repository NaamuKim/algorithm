#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int go(int a, int b){
    if(b==1) return a%c;
    int _c = go(a, b/2);
    _c= (_c * _c) % c;
    if(b%2 & 1) _c=(_c*a)%c;
    return _c;
}

int main(){
    cin >> a >> b >>c;
    cout << go(a,b);
}