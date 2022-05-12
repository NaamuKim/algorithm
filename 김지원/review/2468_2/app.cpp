#include <bits/stdc++.h>

using namespace std;

int a[104][104], vis[104][104],cnt, ret=0, n, dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

void dfs(int y, int x, int t){
    vis[y][x]=1;
    cnt++;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=n || vis[ny][nx]) continue;
        if(a[ny][nx]>=t) dfs(ny,nx, t); 
    }
}

int main(){
    cin >> n;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >>a[i][j];
        }
    }
    for(int t=100; t>=1; t--){
        fill(&vis[0][0], &vis[0][0]+104*104, 0);
        cnt =0;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(a[i][j]>=t && !vis[i][j]) {
                    dfs(i,j,t);
                }
            }
        }
        ret = max(cnt,ret);
    }
    cout << ret <<"\n";
    return 0;
}