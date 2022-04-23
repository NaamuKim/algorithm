#include <bits/stdc++.h>

using namespace std;

int n, m, a,b;
vector<int> adj[1004];
int visited[1004];

void dfs(int x){
    visited[x]=1;
    if(x==n) return;
        for(int there: adj[x]){
            if(!visited[there]) {
                dfs(there);
            }
        }
}

int main(){
    int ret=0;
    cin >> n >>m;
    for(int i =0; i<m; i++){
        cin >>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ret++;
        }
    }
    cout << ret <<"\n";
    return 0;
}