#include <bits/stdc++.h>
using namespace std;
int n, m, ret =1;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    //못 움직임
    if(n==1){
        ret=1;
    } 
    // m이 3이상이면 세칸(두 번)가능
    else if(n==2){
        // 가로 넉넉
        if(m>=7) ret=4;
        else if(m>=5) ret=3;
        else if(m>=3) ret=2;
        else ret=1;
    } 
    else if(n>=3){
        if(m>=7){
            ret=m-2;
        } else{
            ret=min(4,m);
        }
    }
    cout << ret <<"\n";
    return 0;
}