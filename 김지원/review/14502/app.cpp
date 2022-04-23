#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;

int ret, n, m,a,b;
int a[10][10], visited[10][10];
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
vector<pi> v;

void dfs(int y, int x){
    if(a[y][x]==1||visited[y][x]) return;
    vis[y][x]=1;
    for(int i =0; i<4; i++){
        int ny= y+dy[i];
        int nx= x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m || a[ny][nx]==1 ||visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int spread(){
    memset(visited, 0, sizeof(visited));
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(a[i][j]==2) dfs(i,j);
        }
    }
    int ans=0;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(!visited[i][j]&&a[i][j]==0) ans++
        }
    }
    return ans;
}

int main(){
    cin >>n >>m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >>a[i][j];
            if(a[i][j]==0)v[a].push_back(pi(i,j));    
        }
    }
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<i; j++){
			for(int k=0; k<j; k++){
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				ret = max(ret, solve());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
			}
		}
	}
    cout << ret <<"\n";
    return 0;
}