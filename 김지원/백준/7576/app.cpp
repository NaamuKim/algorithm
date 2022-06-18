#include <bits/stdc++.h>
using namespace std;
int n, m, y,x,a[1004][1004],vis[1004][1004] dy[4]={0, 1, 0, -1}, dx[4]={1,0,-1,0};
vector<pair<int, int>> v;

bool check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j]==0){
                for(int k=0;k<4;k++){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if(a[ny][nx]==0) a[ny][nx]=1;
                }
            }
        }
    }
    int ret=0;
while (!q.empty()){ 
        int x = q.front().first; 
        int y = q.front().second; 
        q.pop(); 
        
        for (int i=0; i<4; i++){ 
            int nx = x + dx[i]; 
            int ny = y + dy[i]; 
            if (0<=nx && nx<n && 0<=ny && ny<m){ 
                if (a[nx][ny]==0 && d[nx][ny]==-1){
                    // 익지 않은 토마토 이면서 방문하지 않은 곳 
                    d[nx][ny] = d[x][y] + 1; 
                    q.push(make_pair(nx, ny)); 
                } 
            } 
        } 
    } 
 
    cout << ret <<'\n';
}