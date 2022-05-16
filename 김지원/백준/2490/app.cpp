#include <bits/stdc++.h>

using namespace std;

int a[3][4];

char solve(int n){
    if(n==0) return 'D';
    else if(n==1) return 'C';
    else if(n==2) return 'B';
    else if(n==3) return 'A';
    else if(n==4) return 'E';
}

int main(){
    for(int i =0; i<3; i++){
        int cnt =0;
        for(int j =0; j<4; j++){
            cin >> a[i][j];
            if(a[i][j]==1) cnt++;
        }
        cout << solve(cnt) <<"\n";
    }
    return 0;
}