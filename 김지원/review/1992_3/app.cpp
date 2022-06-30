#include <bits/stdc++.h>
using namespace std;
int n;
char a[65][65];
string solve(int y, int x, int size){
    char val=a[y][x];
    if(size==1) return string(1, val);
    string ret="";
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(a[i][j]!=val){
                ret+='(';
                ret+=solve(y,x,size/2);
                ret+=solve(y,x+size/2,size/2);
                ret+=solve(y+size/2,x,size/2);
                ret+=solve(y+size/2,x+size/2,size/2);
                ret+=')';
                return ret;
            }
        }
    }
    return string(1,val);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >>a[i][j];
        }
    }
    cout << solve(0,0,n)<<"\n";
    return 0;
}