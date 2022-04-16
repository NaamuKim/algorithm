#include <bits/stdc++.h>

using namespace std;

int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0 ,-1, 0};
int a[104][104], b[104][104],visited[104][104], n, ret, tmp =1;

void dfs(int y, int x){
    visited[y][x]=1;
    for(int i = 0; i<4; i++){
        int ny= y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n || nx<0 ||nx>=n) continue;
        if(!visited[ny][nx]&&b[ny][nx]){
            dfs(ny,nx);
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n;j++){
            cin >>a[i][j];
        }
    }
    for(int d = 1; d<101; d++) {
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); 
        tmp=0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j<n;j++){
                if(b[i][j] == 1) continue;
                if(a[i][j] <= d) b[i][j] = 1;
            }
        }
        for(int i=0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(b[i][j]==0&&!visited[i][j]){
                    dfs(i,j);
                    tmp++;
                }
    
            }
        }
        ret=max(tmp,ret);
    }
    cout << ret <<"\n";
    return 0;
}


