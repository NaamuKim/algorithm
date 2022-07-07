#include <bits/stdc++.h>
using namespace std;
int n, l, r, ret, a[54][54],vis[54][54],sum,dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};
vector<pair<int,int>> v;

void dfs(int y, int x, vector<pair<int,int>> &v){
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0||ny>=n||nx<0||nx>=n||vis[ny][nx]) continue;
        if(abs(a[y][x]-a[ny][nx])>=l&&abs(a[y][x]-a[ny][nx])<=r){
            vis[ny][nx]=1;
            sum+=a[ny][nx];
            v.push_back({ny,nx});
            dfs(ny,nx,v);
        }
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        bool flag =0;
        fill(&vis[0][0],&vis[0][0]+54*54,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    v.clear();
                    vis[i][j]=1;
                    v.push_back({i,j});
                    sum=a[i][j];
                    dfs(i,j,v);
                    if(v.size()==1) continue;
                    for(pair<int, int> b: v){
                        a[b.first][b.second]=sum/v.size();
                        flag=1;
                    }
                }
            }
        }
        if(!flag) break;
        ret++;
    }
    cout << ret <<"\n";
}