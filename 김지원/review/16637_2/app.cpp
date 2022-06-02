#include <bits/stdc++.h>
using namespace std;
int n, ret=-987654321;
string s;
vector<int> num;
vector<char> oper_str;

int oper(int a, int b, char c){
    if(c=='+') return a+b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
}

void go(int here, int _num){
    if(here==num.size()-1) {
       ret= max(ret, _num);
       return;
    } 
    go(here+1, oper(_num,num[here+1],oper_str[here]));      

    if(here+2<=num.size()-1){
        int temp = oper(num[here+1],num[here+2],oper_str[here+1]);
        go(here+2, oper(_num, temp, oper_str[here]));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n; i++){
        if(i%2==0) num.push_back(s[i]-'0');
        else oper_str.push_back(s[i]);
    }
    go(0,num[0]);
    cout << ret <<"\n";
    return 0;
}