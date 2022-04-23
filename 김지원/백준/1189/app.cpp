#include <bits/stdc++.h>

using namespace std;
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
int r, c, k, a[6][6], visited[6][6];
int cnt=0;
char x;

int dfs(int y, int x){
    if(y==0&&x==c-1){
        if(visited[y][x]==k) return 1;
        else return 0;
    }
    int ret=0;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || nx<0 || ny>=r || nx >=c||visited[ny][nx]|| a[ny][nx]==1) continue;
        visited[ny][nx]=visited[y][x]+1;
        ret+=dfs(ny,nx);
        visited[ny][nx]=0;
    }
    return ret;
}

int main(){
    cin >>r >> c >> k;
    for(int i =0; i<r; i++){
        for(int j =0; j< c; j++){
            cin >>x;
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    visited[r-1][0]=1;
    cout << dfs(r-1,0);
}