#include <bits/stdc++.h>

using namespace std;

int n, m, a[101][101], vis[101][101], cnt=0, cnt2, dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};
vector<int> ret;
vector<pair<int,int>> v;

void dfs(int y, int x){
    vis[y][x]=1;
    if(a[y][x]==1){
        v.push_back({y,x});
        return;
    }
    for(int i =0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m ||vis[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main(){
    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> a[i][j];
        }    
    }
    while(true){
        fill(&vis[0][0],&vis[0][0]+101*101,0);
        cnt2=0;
        v.clear();
        dfs(0,0);
        for(pair<int,int> item : v) {
            a[item.first][item.second]=0;
            cnt2++;
        }
        bool flag=0;
        cnt++;
        for(int i =0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(a[i][j]==1)flag=1;
            }
        }
        if(!flag) break;
    }
    cout << cnt <<"\n";
    cout << cnt2 << "\n";
    return 0;
}