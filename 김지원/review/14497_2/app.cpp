#include <bits/stdc++.h>
using namespace std;
int n,m,y,x,x1,x2,y1,y2dy[4]={0,1,0,-1},dx[4]={1,0,-1,0},vis[301][301];
char a[301][301];
int main(){
    cin >> n >>m;
    cin >> y1 >> x1 >> y2 >>x2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    vis[y1][x1]=1;
    queue<pair<int,int>> q;
    q.push({y1,x1});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx>0 || nx>=m ||vis[ny][nx]) continue;
        }
    }
}