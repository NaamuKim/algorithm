#include <bits/stdc++.h>
using namespace std;
int m, n, in, ret;
vector<int> v;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >>in;
        v.push_back(in);
    }
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i]+v[j]==m) ret++;
        }
    }
    cout << ret <<"\n";
}