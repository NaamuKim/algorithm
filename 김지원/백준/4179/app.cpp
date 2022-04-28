#include <bits/stdc++.h>

using namespace std;
#define INF 987654321
pair<int, int> pi;
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
int n, m,ret, sy, sx;
char a[1004][1004],  human_check[1004][1004];
int fire_check[1004][1004];

bool in(int a,int b){
	return 1<=a && a<=n && 1<=b && b<=m;
}

int main(){
    queue<pair<int,int>> q; 
    cin >> n >> m;
    fill(&fire_check[0][0], &fire_check[0][0]+1004*1004, INF);
    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            cin >>a[i][j];
            if(a[i][j]=='F'){
                fire_check[i][j]=1;
                q.push({i,j});
            }
            if(a[i][j]=='J'){
                sy=i;
                sx=j;
            }
        }
    }
    while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny= y + dy[i];
			int nx= x + dx[i];
			if(!in(ny,nx)) continue;
			if(fire_check[ny][nx] != INF || a[ny][nx]=='#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ny, nx});
		}
	}
    human_check[sy][sx]=1;
	q.push({sy,sx});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(x == m || y == n || x == 1 || y == 1){
            ret = human_check[y][x];
            break;
		}
        for(int i =0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny,nx)) continue;
            if(human_check[ny][nx] || a[ny][nx]=='#') continue;
            if(fire_check[ny][nx]<=human_check[y][x]+1)continue;
            human_check[ny][nx]=human_check[y][x]+1;
            q.push({ny, nx});   
        }   
    }
    if(ret !=0 ) cout << ret <<"\n";
    else cout <<"IMPOSSIBLE"<<"\n";
    return 0;
}