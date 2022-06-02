#include <bits/stdc++.h>
using namespace std;
int n,in,m;
unordered_map<int, int> umap;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in;
        if(umap.find(in)==umap.end()){
            umap.insert({in, 1});
        } else umap[in]++;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> in;
        if(umap.find(in)==umap.end()) cout << 0<<" ";
        else cout << umap[in]<<" ";
    }
    return 0;
}