#include <bits/stdc++.h>

using namespace std;

int n, m, mx, vis[54][54],y,x;
char a[54][54];

void bfs(int y, int j){
    memset(&vis[0][0], &vis[0][0]+54*54, 0);
    vis[y][x]=1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i =0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if(a[ny][nx] == 'W')continue;
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >>a[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a[i][j]=='L') bfs(i,j);
        }
    }
    cout << mx - 1 << "\n";
}