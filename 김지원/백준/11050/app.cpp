#include <bits/stdc++.h>

using namespace std;

int n, k, ans;

int factorial(int n){
    int ret=1;
    for(int i =1; i<=n; i++){
        ret*=i;
    }
    return ret; 
}

int main(){
    cin >> n >> k;
    ans=factorial(n)/(factorial(k)*factorial(n-k));
    cout << ans;
    return 0;
}