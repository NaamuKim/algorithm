#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, _x, _y;
int a[51][51], vis[51][51], dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

void dfs(int y, int x){
    vis[y][x]=1;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n || nx<0 ||nx>=m ||vis[ny][nx]) continue;
        if(a[ny][nx]==1) dfs(ny,nx);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> m >> n >>k;
        int cnt =0;
        fill(&a[0][0], &a[0][0]+51*51, 0);
        fill(&vis[0][0], &vis[0][0]+51*51,0);
        for(int i =0; i<k; i++){
            cin >> _x >> _y;
            a[_y][_x]=1;
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(a[i][j]==1&&!vis[i][j]) {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}