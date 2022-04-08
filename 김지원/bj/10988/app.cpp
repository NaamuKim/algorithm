#include <bits/stdc++.h>

using namespace std;
string s, temp;

int main(){
    ios_base::sync_with_stdio; cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    temp=s;
    reverse(temp.begin(),temp.end());
    if(temp==s) cout <<1;
    else cout << 0;
    return 0;
}