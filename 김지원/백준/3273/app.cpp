#include <bits/stdc++.h>
using namespace std;
int n, x;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cin >> x;
    sort(v.begin(),v.end());
    int l=0, r=n-1, ret=0;
    while(l<r){
        if(v[l]+v[r]==x) r--, ret++;
        else if(v[l]+v[r]>x) r--;
        else if(v[l]+v[r]<x) l++;
    }
    cout << ret<<"\n";
}