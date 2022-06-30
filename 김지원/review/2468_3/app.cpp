#include <bits/stdc++.h>
using namespace std;
int n, t=0, m=0,ret=1, a[104][104], vis[104][104],dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};

void dfs(int y, int x, int t){
    vis[y][x]=1;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0|| ny>=n || nx<0 || nx>=m || vis[ny][nx]) continue;
        if(a[ny][nx]>t) dfs(ny,nx,t);
    }
    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            m=max(m,a[i][j]);
        }
    }
    while(t<=m+1){
        fill(&vis[0][0],&vis[0][0]+104*104, 0);
        int cnt =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]&&a[i][j]>t){
                    dfs(i,j,t);
                    cnt++;
                }
            }
        }
        ret=max(cnt, ret);
        t++;
    }
    cout << ret <<"\n";
    return 0;
}