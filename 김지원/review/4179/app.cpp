#include <bits/stdc++.h>

using namespace std;
const int INF=987654321;
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
int n, m, fire[1004][1004], man[1004][1004], sy, sx, y, x;
char a[1004][1004];

bool in(int a,int b){
	return 1<=a && a<=n && 1<=b && b<=m;
}

int main(){
    queue<pair<int,int>> q;
    cin >> n >> m;
    fill(&fire[0][0], &fire[0][0]+1004*1004,INF);
    for(int i =1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cin >> a[i][j];
            if(a[i][j]=='F') {
                fire[i][j]=1;
                q.push({i,j})
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
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!in(ny,nx))continue;
            if(fire[ny][nx]!=INF || a[ny][nx]=='#')continue;
            fire[ny][nx]=fire[y][x]+1;
            q.push({ny, nx});
        }
    }
    man[sy][sx]=1;
    q.push({sy,sx});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        if(x == m || y == n || x == 1 || y == 1){
            ret = person_check[y][x];
            break;
		}
        for(int i =0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(!in(ny, nx)) continue;
            if(person_check[ny][nx] || _map[ny][nx]=='#') continue;
            if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret <<"\n";
    else cout <<"IMPOSSIBLE\n";
    return 0;
}