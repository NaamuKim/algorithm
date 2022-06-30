#include <bits/stdc++.h>
using namespace std;
string s;

bool isMeoum(char c){
    if(c==0||c==4||c==8||c==14||c==20) return true;
    return false;
}

bool solve(string s){
    bool flag=false;
        for(int i=0; i<s.size(); i++){
            //1번
            if(isMeoum(s[i]-'a'))flag = true;
            //3번
            if(i!=s.size()-1){
                if(s[i]==s[i+1]&&(s[i]!=4||s[i]!=14)){
                    return false;
                }
            }
        }
        //2번
        for(int i=0; i<s.size()-2; i++){
            if(isMeoum(s[i])&&isMeoum(s[i+1])&&isMeoum(s[i+2])) return false;
        }
        return flag;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    while(true){
        cin >> s;
        string ret;
        if(s=="end") return 0;
        solve(s) ? ret='<'+s+"> "+"is acceptable." : ret='<'+s+"> "+"is not acceptable";
        cout << ret <<"\n";
    }
    return 0;
}