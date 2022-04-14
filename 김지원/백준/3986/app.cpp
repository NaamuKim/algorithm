#include <bits/stdc++.h>

using namespace std;

int n;
string s;
stack<char> stk;
int cnt = 0;

int main(){
    cin >> n;   
    for(int i=0; i<n; i++){
        while( !stk.empty() ) stk.pop();
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            //스택이 비어있거나 마지막 것과 같지 않으면 푸쉬
            if (stk.empty()==true || s[j]!=stk.top()) stk.push(s[j]);
            else if(s[j]==stk.top()) stk.pop();
        }
        if(stk.empty()==true) cnt++;
    }
    cout << cnt;
}