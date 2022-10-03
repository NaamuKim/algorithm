#include <bits/stdc++.h>
using namespace std;
int t, dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0},a[104][104],vis[104][104],b[104][104], n,tmp,ret;

void dfs(int y, int x){
    vis[y][x]=1;
    for(int i = 0; i<4; i++){
        int ny= y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n || nx<0 ||nx>=n) continue;
        if(!vis[ny][nx]&&b[ny][nx]==0){
            dfs(ny,nx);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int p=1; p<=t; p++){
        cin >> n;
        fill(&a[0][0],&a[0][0]+104*104,0);
        fill(&b[0][0],&b[0][0]+104*104,0);
        ret=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> a[i][j];
            }
        }
        for(int d = 0; d<101; d++) {
            tmp=0;
            fill(&vis[0][0],&vis[0][0]+104*104,0);
            for(int i = 0; i< n; i++){
                for(int j = 0; j<n;j++){
                    if(b[i][j] == 1) continue;
                    if(a[i][j] <= d) b[i][j] = 1;
                }
            }
            
            for(int i=0; i< n; i++){
                for(int j = 0; j < n; j++){
                    if(b[i][j]==0&&!vis[i][j]){
                        dfs(i,j);
                        tmp++;
                    }
                }
            }
            ret=max(tmp,ret);
        }
        cout<<"#"<<p <<" "<< ret <<"\n";
    }
    return 0;
}