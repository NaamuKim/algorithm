#include <bits/stdc++.h>
typedef pair<int,int> pi;
using namespace std;
vector<pi> vc;
int n, m;
int a[10][10];
bool vis[10][10];
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};

void dfs(int y, int x){
    vis[y][x]=true;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dy[i];
        if(ny <0 || nx <0 || ny>n-1 || nx >m-1|| vis[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> a[i][j];
            if(!a[i][j]) vc.push_back(pi(i,j));
        }
    }
    int res=0;
}