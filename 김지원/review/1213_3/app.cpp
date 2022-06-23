#include <bits/stdc++.h>
using namespace std;
string s, mid, ret;
map<char, int> _map;
int flag=0;
int main(){
    cin >> s;
    for(int i=0; i<s.size(); i++){
        _map[s[i]]++;
    }
    for(auto it: _map){
        if(it.second & 1){
            flag++;
            mid=it.first;
        }
        if(flag>2) break;

    }
}