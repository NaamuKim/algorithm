#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
vector<pi> v;
int n, m;
int a[10][10];
bool vis[10][10];
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};

void dfs(int y, int x){
    if(a[y][x] == 1 || vis[y][x]) return;
    vis[y][x]=true;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny <0 || nx <0 || ny>n-1 || nx >m-1) continue;
        dfs(ny, nx);
    }
}

int solve(){
    memset(vis, 0, sizeof(vis));
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a[i][j]==2) dfs(i,j);
        }
    }
    int ret =0;
    for(int i= 0; i<n;i++){
        for(int j =0; j<m; j++){
            if(a[i][j]==0&&!vis[i][j]) ret++;
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> a[i][j];
            if(!a[i][j]) v.push_back(pi(i,j));
        }
    }
    int ret = 0;
    for(int i =0; i < v.size(); i++){
        for(int j =0; j < i; j++){
            for(int k =0; k < j; k++){
                a[v[i].first][v[i].second]=a[v[j].first][v[j].second]=a[v[k].first][v[k].second] =1;
                ret=max(ret,solve());
                a[v[i].first][v[i].second]=a[v[j].first][v[j].second]=a[v[k].first][v[k].second] =0;    
            }
        }
    }
    cout << ret;
    return 0;
}