#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int ret=0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            cin >> a[i][j];
            // i,j 둘다 짝이거나  i, j 둘다 홀일때
            if(a[i][j]=='F'){
                if((i&1)==0&&(j&1)==0) ret++;
                else if((i&1)==1&&(j&1)==1) ret++;
            } 
        }
    }
    cout << ret <<"\n";
    return 0;
}