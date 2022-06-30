#include <bits/stdc++.h>
using namespace std;
int r, c, n;
char a[201][201];
vector<pair<int,int>> v;
void explode(){
    fill(&a[0][0],&a[0][0]+201*201,'O');
    for(auto it: v){
        int ny=it.first;
        int nx=it.second;
        a[ny][nx]='.';
        if(ny-1>=0) a[ny-1][nx]='.';
        if(ny+1<r) a[ny+1][nx]='.';
        if(nx-1>=0) a[ny][nx-1]='.';
        if(nx+1<c) a[ny][nx+1]='.';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> n;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
            if(a[i][j]=='O') v.push_back({i,j});
        }
    }
    if(n==1){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout <<a[i][j];
            }
            cout <<"\n";
        }
    }else if(n%2==0){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout <<'O';
            }
            cout <<"\n";
        }
    } else if(n%4==3){
        explode();
        v.clear();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout <<a[i][j];
            }
            cout <<"\n";
        }
    } else if(n%4==1){

    }
    return 0;
}