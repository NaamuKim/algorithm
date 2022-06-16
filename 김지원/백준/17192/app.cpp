#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2, site;
map<string,string> sMap;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s1>> s2;
        sMap.insert({s1, s2});
    }
    for(int i=0; i<m; i++){
        cin >> site;
        cout << sMap[site] <<"\n";
    }
    return 0;
}