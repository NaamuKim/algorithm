#include <bits/stdc++.h>
using namespace std;
int n,ret=0,d[200001];
string s;
int cnt=0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cin >> s;
    stack<int> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') stk.push(i);
        else if(stk.size()) {
            d[i]=d[stk.top()]=1;
            stk.pop();
        }
    }
    for(int i=0; i<s.size(); i++){
        if(d[i]){
            cnt++;
            ret=max(ret,cnt);
        } else cnt =0;

    }   
    cout << ret <<"\n";
    return 0;
}