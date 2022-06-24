#include <bits/stdc++.h>
using namespace std;
int n, ret=0;
string s;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(!stk.empty()&&stk.top()==s[i]){
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        if(stk.empty()) ret++;
    }
    cout << ret <<"\n";
}