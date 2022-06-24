#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
ll go(ll a, ll b){
    if(b==1) return a%c;
    int _c=go(a,b/2);
    _c=(_c*_c)%c;
    if(b&1) _c=(_c*a)%c;
    return _c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b>> c;
    cout << go(a, b);   
}