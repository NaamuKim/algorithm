#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main(){
    cin >> s1 >> s2;
    string ret;
    for(char a : s1){
        ret += a;
        if(ret.size() >= s2.size() && ret.substr(ret.size() - s2.size(), s2.size()) == s2){
            ret.erase(ret.end() - s2.size(), ret.end()); 
        }
    }
    if(!ret.size())cout << "FRULA" << "\n";
    else cout << ret << "\n";
}