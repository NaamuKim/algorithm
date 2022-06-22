#include <bits/stdc++.h>

using namespace std;

string s, ret;
map<char, int> _map;
int flag=0;
char mid;

int main(){
    cin >> s;
    for(int i=0; i <s.size();i++){
        _map[s[i]]++;
    }
    for(auto it : _map){
        if(it.second & 1) {
            flag++;
            mid=it.first; 
        }
        if(flag==2) break;
        for(int j = 0; j < _map.size();j+=2){
            cout << it.first << "\n";
            ret = it.first + ret;
            ret += it.first;
        }
    }
    if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag==2) cout << "I'm Soory Hansoo";
    else cout <<ret<<"\n";
}