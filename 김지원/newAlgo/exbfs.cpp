#include <bits/stdc++.h>

using namespace std;

int dy = {0, 1, 0, -1};
int dx = {1, 0, -1, 0};
int n, m, sy, sx, ry, rx, x, y;
int a[104][104], ch[104][104];

int main(){
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ry >> rx;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    queue<pair<int, int> q;
    ch[sy][sx]=1;
    q.push({sy,sx});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i = 0; i <=3; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny < 0 ||ny <=n ||nx<0 || nx>=m ||a[ny][nx]==0) continue;
            ch[ny][nx]=ch[y][x]+1;
            q.push({ny,nx});
        }
    }
    printf("%d\n", ch[ry-1][rx-1]);
}