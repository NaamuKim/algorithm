#include <bits/stdc++.h>

using namespace std;

int n, m, a[104][104], x, y;
int ch[104][104];
queue<pair<int, int>> q;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int main(){
   scanf("%d %d", &n, &m); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    } 
    q.push({0,0});
    ch[0][0]=1;
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i =0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=n ||nx <0 || nx>=m || a[ny][nx]==0) continue;
            if(ch[ny][nx]) continue;
            ch[ny][nx] = ch[y][x] + 1; 
            q.push({ny, nx}); 
        }
    }
    cout << ch[n-1][m-1];
    return 0;
}