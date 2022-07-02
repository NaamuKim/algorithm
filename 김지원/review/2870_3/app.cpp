#include <bits/stdc++.h>
using namespace std;
int n;
string ret, s;
vector<string> v;
bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    else return a.size()<b.size();
}
void go(){
    if(ret.size()){
        while(true){
            if(ret.size()&&ret.front()=='0') ret.erase(ret.begin());
            else break;
        }
        if(ret.size()==0)ret="0";
        v.push_back(ret);
        ret="";
    }
}
    int main(){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<s.size(); j++){
                if(s[j]<58) ret+=s[j];
                else go();
            }
            go();
        }
        sort(v.begin(),v.end(),cmp);
        for(string i : v) cout << i<<"\n";
    }   
