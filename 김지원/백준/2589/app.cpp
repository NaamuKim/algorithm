#include<bits/stdc++.h>

using namespace std;

int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
int n, m, vis[54][54], mx=0;
char a[54][54];
vector<pair<int, int>> v;
void bfs(int y, int x){
    memset(vis,0,sizeof(vis));
    vis[y][x]=1;
    queue<pair<int, int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x)=q.front(); q.pop();
        for(int i =0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m|| vis[ny][nx]||a[ny][nx]=='W') continue;
            vis[ny][nx]=vis[y][x]+1;
            q.push({ny,nx});
            mx=max(mx, vis[ny][nx]);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a[i][j]=='L') bfs(i,j);
        }
    }
    cout << mx -1 <<"\n";
}