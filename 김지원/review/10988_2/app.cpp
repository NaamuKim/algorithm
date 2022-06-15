#include <bits/stdc++.h>
using namespace std;
string s, newS;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    newS=s;
    reverse(s.begin(),s.end());
    s==newS ? cout << 1 <<"\n" : cout << 0 <<"\n";
    return 0;
}