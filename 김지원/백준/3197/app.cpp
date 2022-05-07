#include <bits/stdc++.h>

using namespace std;

int n, m, ret, sy, sx,day;
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1, 0};
char a[1504][1504];
string s;
bool isSwanMeet;
int vis_swan[1504][1504], vis[1504][1504];

queue<pair<int,int>> waterQ, water_tempQ, swanQ, swan_tempQ;

void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
}

void water_melting(){
    while(waterQ.size()){
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();
        for(int i =0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m|| vis[ny][nx]) continue;
            if(a[ny][nx]=='X'){
                vis[ny][nx]=1;
                water_tempQ.push({ny,nx});
                a[ny][nx]='.';
            }
        }
    }
}

void move_swan(){
    while(swanQ.size()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;  
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || vis_swan[ny][nx])continue;
            if(a[ny][nx] == '.')swanQ.push({ny, nx});
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(a[ny][nx] == 'L'){isSwanMeet = true; return;}
            vis_swan[ny][nx] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i =0; i<n; i++){
        cin >> s;
        for(int j =0; j<s.size(); j++){
            a[i][j]=s[j];
            if(a[i][j]=='L') {sy= i; sx=j;}
            if(a[i][j]=='.'||a[i][j]=='L') vis[i][j]=1, waterQ.push({i,j});
        }
    }
    swanQ.push({sy,sx});
    vis_swan[sy][sx]=1;
    while(!isSwanMeet){
        move_swan();
        if(isSwanMeet) break;
        water_melting();
        waterQ=water_tempQ;
        swanQ=swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day <<"\n";
    return 0;
}