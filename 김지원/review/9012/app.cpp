#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> s;
        stack<char> stk;
        bool flag =false;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='(') stk.push('(');
            else if(stk.size()&&s[j]==')') stk.pop();
            else if(stk.empty()&&s[j]==')') flag =true;
        }
        if(!stk.empty()||flag) cout <<"NO"<<"\n";
        else cout <<"YES"<<"\n";
    }
    return 0;
}