#include <bits/stdc++.h>
using namespace std;
string s;
bool flag;
long long int ret=0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    int sum =0;
    for(int i=0; i<s.size(); i++){
        sum+=s[i]-'0';
    }
    sort(s.begin(),s.end(),greater<>());
    if(s[s.size()-1]!='0'||sum%3!=0) cout << -1 <<"\n";
    else cout << s <<"\n";
    return 0;
}