#include <bits/stdc++.h>
using namespace std;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int m, n, k, t, x, y;
int visited[51][51], a[51][51];

void dfs(int y, int x){
    visited[y][x]=1;
    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny >= n ||nx <0 || nx >=m)continue;
        if(!visited[ny][nx]&&a[ny][nx]==1) {
            dfs(ny,nx);
        }
    }
}

int main(){
    cin >> t;
    for(int i =0; i<t;i++){
        int cnt =0;
        cin >> m >> n >> k;
        for(int j =0; j<k; j++){
            cin >> x >> y;
            a[y][x]=1;
        }
        for(int y=0; y<n; y++){
            for(int x =0; x<m; x++){
                if(!visited[y][x] && a[y][x]==1){
                    cout << y << " "<< x <<"\n";
                    cnt++;
                    dfs(y,x);
                }
            }
        }
        cout << cnt << "\n";
    }
}