#include <bits/stdc++.h>
using namespace std;
int n, m, vis[54][54], ret, dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};
char a[54][54];

void bfs(int y, int x){
    fill(&vis[0][0],&vis[0][0]+54*54, 0);
    vis[y][x]=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(!vis[ny][nx]&&a[ny][nx]=='L'){
                q.push({ny,nx});
                vis[ny][nx]=vis[y][x]+1;
                ret=max(vis[ny][nx], ret);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='L'){
                bfs(i,j);
            }
        }
    }
    cout << ret-1 <<"\n";
}