#include <bits/stdc++.h>
using namespace std;
int n;
long long ret;
int main (){
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        if(ret<v[i].first) ret=v[i].first+v[i].second;
        else ret+=v[i].second;
    }
    cout << ret <<"\n";
    return 0;
}