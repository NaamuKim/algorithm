#include <bits/stdc++.h>

using namespace std;

int m,n,k,newy1,x1, y2,x2;
int num=0;
vector<int> cnt;
int a[104][104];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void dfs(int x, int y){
    a[y][x]=1;
    for(int i = 0; i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=m || nx < 0 || nx >=n) continue;
        if(a[ny][nx]==0){
            dfs(ny,nx);
            num++;
        }
    }
}


int main(){
    cin >> m >> n >> k;
    for(int i =0; i<k; i++){
        cin >> x1 >> newy1 >> x2 >>y2;
        for(int y=newy1; y<y2; y++){
            for(int x= x1; x<x2; x++){
                a[y][x]=1;
            }
        }
    }
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            if(a[i][j]==0) {
                dfs(i,j);
                cnt.push_back(num);
                num=0;
            }
        }
    }
    sort(cnt.begin(),cnt.end());
    cout << cnt.size() << "\n";
    for(int i =0; i<cnt.size();i++){
        cout << cnt[i] << " ";
    }
    return 0;
}