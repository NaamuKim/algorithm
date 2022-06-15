#include <bits/stdc++.h>
using namespace std;
int n;
string s, ret;
map<char, int> M;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(M.find(s[0])==M.end()){
            M.insert({s[0],1});
        }else{
            M[s[0]]++;
        }
    }

    for(auto it: M){
        if(it.second>=5) ret+=it.first;
    }
    sort(ret.begin(),ret.end());
    if(ret.size()) cout << ret <<"\n";
    else cout << "PREDAJA" <<"\n";
    return 0;
}