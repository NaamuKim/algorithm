#include <bits/stdc++.h>
using namespace std; 
int n,m, dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0},mx=0;
char a[54][54];
int vis[54][54];
void bfs(int y, int x){
    fill(&vis[0][0],&vis[0][0]+54*54,0);
    vis[y][x]=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x)= q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny= y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(a[ny][nx]=='L'&&!vis[ny][nx]) {
                vis[ny][nx]=vis[y][x]+1;
                q.push({ny,nx});
                mx=max(vis[ny][nx], mx);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='L') bfs(i,j);
        }
    }
    cout << mx-1 <<"\n";
    return 0;
}