#include <bits/stdc++.h>
using namespace std;
string s1, s2, ret;
int main(){
    cin >> s1 >> s2;
    for(int i=0; i<s1.size(); i++){
        ret+=s1[i];
        if(ret.size()>=s2.size()&&ret.substr(ret.size()-s2.size(),s2.size())==s2){
            ret.erase(ret.end() - s2.size(), ret.end());
        }
    }
    for(int i=0; i<ret.size(); i++) cout <<ret[i];
    return 0;
}