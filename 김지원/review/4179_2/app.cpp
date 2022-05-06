#include <bits/stdc++.h>

using namespace std;

int n, m, sy, sx, y, x, INF=987654321,ret;
char a[1004][1004];
int fire[1004][1004], human[1004][1004];
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};

bool in (int y, int x){
    if(y<0 || y>=n || x<0 || x>=n) return false;
    return true;
}

int main(){
    cin >> n >> m;
    fill(fire[0][0], fire[0][0]+1004*1004,)
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j]=='F'){
                f[i][j]=1;
                q.push({i,j});
            }
            if(a[i][j]=='J'){
                sy=i;
                sx=j;
            }
        }
    }
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i =0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(!in(ny,nx)) continue;
            if(fire[ny][nx]||a[ny][nx]=='#') continue;
            fire[ny][nx]=fire[y][x]+1;
            q.push({ny,nx});
        }
    }
    human[sy][sx]=1;
    queue.push({sy,sx});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        if(y==1 || x==1 || x==m || y==n) {
            ret=human[y][x];
            break;
        }
        for(int i =0; i<4; i++){
            int ny= y+dy[i];
            int nx = x+dx[i];
            if(!in(ny,nx)) continue;
            if(human[ny][nx] || a[ny][nx]=='#') continue;
            if(fire[ny][nx]<=human[ny][nx]+1) continue;
            human[ny][nx]=human[y][x]+1;
            q.push(ny, nx);
        }
    }
    if(ret != 0) cout << ret <<"\n";
    else cout <<"IMPOSSIBLE\n";
    return 0;
}
