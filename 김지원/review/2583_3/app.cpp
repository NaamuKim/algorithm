#include <bits/stdc++.h>
using namespace std;
int n, m, k,_x1,_x2,_y1,_y2,a[101][101],vis[101][101], ret=0;
vector<int> v;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int dfs(int y, int x){
    vis[y][x]=1;
    int cnt=1;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
        if(a[ny][nx]==0&&!vis[ny][nx]) cnt+=dfs(ny,nx);
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    while(k--){
        cin >> _x1 >> _y1 >> _x2 >> _y2;
        for(int i=_y1; i<_y2; i++){
            for(int j=_x1; j<_x2; j++){
                a[i][j]=1;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]&&a[i][j]==0){
                v.push_back(dfs(i,j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() <<"\n";
    for(int it: v) cout << it <<" ";
    return 0;
}