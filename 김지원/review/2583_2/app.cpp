#include <bits/stdc++.h>

using namespace std;

int a[104][104], vis[104][104], _x1, _y1, _x2, _y2, n, m, k, dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
vector<int> v;

int dfs(int y, int x){
    a[y][x]=1;
    int ret =1;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny <0 || ny>=n || nx<0 || nx>=m) continue;
        if(a[ny][nx]==0) ret+=dfs(ny,nx);
    }
    return ret;
}

int main(){
    cin >>n >> m >>k;
    for(int i =0; i<k; i++){
        cin >> _x1 >> _y1 >> _x2 >> _y2;
        for(int i=_y1; i<_y2; i++){
            for(int j =_x1; j<_x2; j++){
                a[i][j]=1;
            }
        } 
    }
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(!a[i][j]) {
                v.push_back(dfs(i,j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size()<<'\n';
    for(int item: v) cout << item <<" ";
}