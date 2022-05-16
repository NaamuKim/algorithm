#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> ret;
string ppo;
void go(){
    while(true){
        if(ppo.size()>=2&&ppo[0]=='0') ppo.erase(ppo.begin());
        else break;
    }
    if(ppo.size())ret.push_back(ppo);
    ppo="";
}

bool cmp(string &a, string &b){
    if(a.size()==b.size()) return a<b;
    return a.size() < b.size();
}

int main(){
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> s;
        for(int j =0; j<s.size(); j++){
            if(s[j]<58) ppo+=s[j];
            else{
                //벡터 정리
                go();
            }
        }
        go();
    }
    sort(ret.begin(), ret.end(), cmp);
    for(string item: ret){
        cout << item <<"\n";
    }
    return 0;
}   