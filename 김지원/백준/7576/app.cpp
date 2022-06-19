#include <bits/stdc++.h>
using namespace std;
int n, m, y,x,a[1004][1004],vis[1004][1004], dy[4]={0, 1, 0, -1}, dx[4]={1,0,-1,0};
queue<pair<int, int>> q;

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            vis[i][j]=-1;
            if(a[i][j]==1) {
                q.push({i,j});
                vis[i][j]=0;
            }
        }
    }
    while (!q.empty()){ 
        tie(y,x)=q.front();
        q.pop(); 
        for (int i=0; i<4; i++){ 
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if (a[ny][nx]==0 && vis[ny][nx]==-1){
                vis[ny][nx] = vis[y][x] + 1; 
                q.push({ny,nx}); 
            } 
        }
    } 
    int ret=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0&&vis[i][j]==-1){
                cout << -1 <<"\n";
                return 0;
            }
            ret=max(ret,vis[i][j]);
        }
    }
    cout << ret <<"\n";
    return 0;
}