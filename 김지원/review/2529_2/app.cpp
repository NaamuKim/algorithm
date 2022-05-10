#include <bits/stdc++.h>

using namespace std;

int n;
char a[10];
vector<string> ret;

bool isGood(char a, char b, char op){
    if(a > b && op == '>') return true;
    if(a < b && o p== '<') return true;
    return false;
}

void go(int idx, string num){
    if(idx==n+1) {
        ret.push_back(num);
        return;
    }
    for(int i =1; i<=9; i++){
        if(vis[i]) continue;
        if(idx==0 || isGood(num[idx-1],i+'0',a[idx-1])){
            vis[idx]=1;
            go(idx+1, num+to_string(i));
            vis[idx]=0;
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> a[i];
    }
    go(0,""); 
    sort(ret.begin(), ret.end());
    cout << ret[ret.size()-1] <<"\n" << ret[0]<<"\n";
}