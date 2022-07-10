#include <bits/stdc++.h>
using namespace std;
string s1, s2, ret;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    for(char it: s1){
        ret+=it;
        if(ret.size()>=s2.size()&&ret.substr(ret.size()-s2.size())==s2){
            ret.erase(ret.end() - s2.size(), ret.end());
        }
    }
    if(ret.size()){
        for(int i=0; i<ret.size(); i++) cout << ret[i];
    }
    else cout << "FRULA"<<"\n";
    return 0;
}