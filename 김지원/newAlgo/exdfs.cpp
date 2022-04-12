#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
bool ch[100][100];
int dy={1,0,-1,0};
int dx={0,1,0,-1};
int cnt=0;

int DFS(int y,int x){
        ch[y][x]=1;
            for(int i=0;i<=3;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(ny<0&&ny>=n&&nx<0&&nx>=m) continue;
                if(a[ny][nx]==1&&!ch[ny][nx]){
                    DFS(ny, nx);
                }
        }
    }

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j = 0; j<m;j++){
            cin>>arr[i][j];
            ch[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<m;j++){
            cnt++;
            DFS(i,j);
        }
    }
}    
