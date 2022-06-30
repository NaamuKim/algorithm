#include <bits/stdc++.h>
using namespace std;
int n,m,j,k,ret=0;
int main(){
    cin >> n >> m >> j;
    int l =1;
    for(int i =0; i<j; i++){
        int r=l+m-1;
        cin >> k;
        if(k>=l && k<=r) continue;
        else{
            if(k<l){
                ret+=(l-k);
                l=k;
            } else{
                l+=(k-r);
                ret+=(k-r);
            }
        }
    }
    cout << ret <<"\n";
    return 0;
}