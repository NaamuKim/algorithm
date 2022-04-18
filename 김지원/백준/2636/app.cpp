#include <bits/stdc++.h>

using namespace std;

int h, w, a[101][101],visited[101][101],cnt,cnt2;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector <pair<int, int>> v;


void go(int y, int x){
    visited[y][x]=1;
    if(a[y][x]==1){
        v.push_back({y,x});
        return;
    }
    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx<0 || ny<0 || nx>=w ||ny>=h ||visited[ny][nx]) continue;
        go(ny,nx);
    }
};

int main(){
    cnt =0;
    cnt2=0;
    cin >> h >> w;
    for(int i =0; i<h;i++){
        for(int j =0; j<w; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        cnt2 =0;
        fill(&visited[0][0], &visited[0][0]+101*101, 0);
        v.clear();

        go(0,0);
        for(pair<int, int> b : v) if(a[b.first][b.second] == 1) cnt2++; 
        for(pair<int, int> b : v) a[b.first][b.second] = 0; 

        cnt++;
        bool flag = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(a[i][j] != 0) flag = 1;
            }
        }
        if(!flag) break;
    }
    cout << cnt << "\n";
    cout << cnt2 << "\n"; 
}