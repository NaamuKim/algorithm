#include <bits/stdc++.h>

using namespace std;

int n;
string s;
char a[104][104];
string ret;
string quard(int y, int x, int size){
    if(size==1) return ret+=string(1,a[y][x]);
    bool flag =0;
    int b=a[y][x];
    for(int i =y; i<y+size; i++){
        for(int j =x; j<x+size; j++){
            if(a[i][j]!=b) {
                flag=1;  
                break;
            }
        }
    }
    if(flag){
        ret+=quard()
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    quard(0,0,n);
    cout << ret << "\n";
    return 0;
}

