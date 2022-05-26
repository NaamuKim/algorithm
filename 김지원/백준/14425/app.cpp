#include <bits/stdc++.h>
using namespace std;
int n, m, ret=0;
string s;
unordered_map<string, int> umap;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >>m;
    for(int i=0; i<n; i++){
        cin >>s;
        umap.insert({s,i});
    }
    for(int i=0; i<m; i++){
        cin >> s;
        auto search= umap.find(s);
        if(search!=umap.end()) ret++;
    }
    cout << ret <<"\n";
    return 0;
}