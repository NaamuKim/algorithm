#include <bits/stdc++.h>

using namespace std;

int n;
string s, p;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> p;
    int pos= p.find('*');
    string pre= p.substr(0,pos);
    string suf = p.substr(pos+1);
    while(n--){
        string ret="DA";
        cin >> s;
        for(int i =0; i<pre.size(); i++){
            if(pre[i]!=s[i]) ret="NE";
        }
        for(int i=0; i<suf.size();i++){
            if(suf[i]!=s[s.size()-1-i]) ret="NE";
        }
        cout << ret <<"\n";
    }
}