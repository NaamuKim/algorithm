#include <bits/stdc++.h>

using namespace std;

int n,arr[50],ret;

int dfs(int m){
    if(m<=1) return m;
    return dfs(m-1)+ dfs(m-2);
}

int main(){
    cin >> n;
    cout << dfs(n) <<"\n";
    return 0;
}