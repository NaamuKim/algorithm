#include <bits/stdc++.h>
using namespace std;
int n, m, a[10][10],vis[10][10], ret=0, dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1 ,0};
vector<pair<int,int>> v;

void dfs(int y, int x){
    vis[y][x]=1;
    for(int i=0; i<4; i++){
        int ny =y+dy[i];
        int nx =x+dx[i];
        if(ny<0 || ny>=n ||nx<0 || nx>=m) continue;
        if(a[ny][nx]!=1&&!vis[ny][nx]) dfs(ny,nx);
    }
    return;
}

int solve(){
    fill(&vis[0][0],&vis[0][0]+10*10, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==2&&!vis[i][j]) dfs(i,j);
        }
    }
    int ret=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==1||a[i][j]==1||a[i][j]==2) ret++;
        }
    }
    return n*m-ret;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j]==0) v.push_back({i,j});
        }
    }
    for(int i=0; i<v.size()-2;i++){
        for(int j=i+1;j<v.size()-1;j++){
            for(int k=j+1; k<v.size(); k++){
                a[v[i].first][v[i].second]=a[v[j].first][v[j].second]=a[v[k].first][v[k].second]=1;
                ret=max(ret, solve());
                a[v[i].first][v[i].second]=a[v[j].first][v[j].second]=a[v[k].first][v[k].second]=0;
            }
        }
    }
    cout << ret <<"\n";
    return 0;
}