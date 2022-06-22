#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        map<string, int> _map;
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> s1 >> s2;
           _map[s2]++;
        }
        int ret =1;
        for(auto it: _map){
            ret*=(it.second+1);
        }
        ret-=1;
        cout << ret<<"\n";
    }
    return 0;
}