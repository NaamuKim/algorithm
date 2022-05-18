#include <bits/stdc++.h>
using namespace std;

int n, m, ret=0;
vector<pair<int,int>> v;
int a[10][10], vis[10][10], dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};

void dfs(int y, int x){
    vis[y][x]=1;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m ||vis[ny][nx]) continue;
        if(a[ny][nx]==0){
            dfs(ny,nx);
        }
    }
}

int solve(){
    fill(&vis[0][0],&vis[0][0]+10*10,0);
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a[i][j]==2 &&!vis[i][j]) dfs(i,j);
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0&&!vis[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j]==0)v.push_back({i,j});
        }
    }

    for(int i =0; i<v.size(); i++){
        for(int j =0; j<i; j++){
            for(int k=0; k<j; k++){
                a[v[i].first][v[i].second]=a[v[j].first][v[j].second]=a[v[k].first][v[k].second]=1;
                ret=max(ret,solve());
                a[v[i].first][v[i].second]=a[v[j].first][v[j].second]=a[v[k].first][v[k].second]=0;
            }
        }
    }
    cout << ret <<"\n";
    return 0;
}