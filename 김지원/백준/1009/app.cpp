#include <bits/stdc++.h>

using namespace std; 
int n,a,b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> a >> b;
        int ret =a ;
        b=b%4+4;
        for(int j =2; j<=b; j++){
            ret=ret*a%10;
        }
        if(ret==0) ret=10;
        cout << ret <<"\n";
    }
    return 0;
}  
