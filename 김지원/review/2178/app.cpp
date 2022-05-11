#include <bits/stdc++.h>

using namespace std;

int n, m, y, x, a[104][104], vis[104][104], dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
string s;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i =0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j]=stoi(s[j]);
            cout <<a[i][j] <<" ";
        }
        cout <<"\n";
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=1;
    while(q.size()){
        tie(y,x)=q.front(); q.pop();
        for(int i =0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m ||vis[ny][nx]||a[ny][nx]==0) continue;
            if(a[ny][nx]==1){
                vis[ny][nx]=vis[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
    cout << vis[n-1][m-1]-1 <<"\n";
    return 0;
}