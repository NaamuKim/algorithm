#include <bits/stdc++.h>

using namespace std;

int n, m, in;
unordered_map<int, int> umap;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in;
        umap[in]=1;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> in;
        umap.find(in)==umap.end() ? cout << 0 <<" " : cout << 1 <<" "; 
    }
    return 0;
}