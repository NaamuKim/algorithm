#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    while(true){
        getline(cin, s);
        if(s==".") return 0;
        stack<char> stk;
        bool flag =false;
        for(int i=0; i<s.size(); i++){
            cout << s[i]<<" ";
            if(s[i]=='('||s[i]=='[') {
                if(s[i]=='(') stk.push(')');
                else stk.push(']');
            }
            else if(s[i]==')' || s[i]==']'){
                if(!stk.empty()&&stk.top()==s[i]) stk.pop();
                else flag =true; break;
            }
        }
        if(stk.empty()&&!flag) cout <<"yes"<<"\n";
        else cout << "no" <<"\n";
    }
    return 0;
}