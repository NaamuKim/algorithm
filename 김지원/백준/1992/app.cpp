#include <bits/stdc++.h>

using namespace std;

int n, a[68][68];
string ret;


string dfs(int y, int x, int size){
    if(size==1) return string(1, a[y][x])
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=dot){
                ret+="(";
                dfs(n/2, dot);
                return;
            }
        }
    }
    ret+=dot;
}

int main(){
    cin >> n;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >>a[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            dfs(8,a[i][j]);
        }
    }
    cout << ret;
    return 0;
}