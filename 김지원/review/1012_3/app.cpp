#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, y, x;
int a[54][54], vis[54][54], dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

void dfs(int y, int x){
    vis[y][x]=1;
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(a[ny][nx]==1&&!vis[ny][nx]) dfs(ny, nx);
    }
}
int main(){
    cin >> t;
    while(t--){
        fill(&a[0][0], &a[0][0]+54*54, 0);
        fill(&vis[0][0],&vis[0][0]+54*54, 0);
        cin >> m >> n >>k;
        int ret =0;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            a[y][x]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]==1&&!vis[i][j]) {
                    dfs(i,j);
                    ret++;  
                }
            }
        }
        cout << ret <<"\n";
    }
    return 0;
}