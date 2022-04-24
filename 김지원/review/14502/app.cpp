#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
int a[10][10], ret;
bool vis[10][10];
vector<pi> v;

void dfs(int y, int x){
    vis[y][x]=1;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0 || ny >=n || nx<0 || nx >=m ||vis[ny][nx]|| a[ny][nx]==1) continue;
        dfs(ny,nx);
    }
}

int solve(){
    memset(vis,0, sizeof(vis));
    for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] == 2) dfs(i, j);
		}
	}
    int ans=0;
    for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j] && a[i][j] == 0) ans++;
		}
	}
	return ans;
}


int main(){
    cin >>n >>m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> a[i][j];
            v.push_back({i,j});
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<i; j++){
            for(int k =0; k<j; k++) {
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] =1;
                ret=max(ret, solve());
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] =0;
            }
        }
    }
    cout << ret;
    return 0;
}