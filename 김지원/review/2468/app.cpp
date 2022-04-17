#include <bits/stdc++.h>

using namespace std;
int n, a[101][101], b[101][101];
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
int visited[101][101];
int answer, ret=1;

void dfs(int y, int x){
    visited[y][x]=1;
    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >=n || nx>=n || nx<0) continue;
        if(!visited[ny][nx]&&b[ny][nx]==1){
            dfs(ny,nx);
        } 
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int q=100; q>=1; q--){
        ret = 0;
        fill(&visited[0][0], &visited[101][101], 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j]>q) b[i][j]=1;
                else b[i][j]=0;
            }
        }
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]==0&&b[i][j]==1){
                    ret++;
                    dfs(i,j);
                }
            }
        }
        cout << answer << " " << ret << "\n";
        answer=max(ret, answer);
    }
    cout << answer; 
}