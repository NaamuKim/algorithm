#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b){
    //거듭제곱을 분할했을 때 1이 되면 a를 나눈 나머지를 리턴
    if(b == 1) return a % c;
    ll newC=go(a, b/2);
    newC= (newC*newC) % c;
    if(b % 2 & 1) newC=(newC*a)%c;
    return newC;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
    return 0;
}