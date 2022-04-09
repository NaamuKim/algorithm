#include <bits/stdc++.h>

using namespace std;

int n, pos;
string pat, pre, suf, s;
int main(){
    cin >> n;
    cin >> pat;
    pos = pat.find('*');
    pre = pat.substr(0, pos);
    suf = pat.substr(pos+1, pat.size());
    // 받은 문자열에 pre와 suf이 같은 지 확인하고 
    // 반례는 받은 문자열이 더 작은데 통과되는 것
    for(int i = 0; i < n; i++){
        cin >> s;
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";
        }
        else{
            if(s.substr(0,pre.size())==pre && s.substr(s.size()-suf.size(), s.size())==suf){
                cout << "DA\n";
            }
            else cout << "NE\n";
        }
    }
    return 0;
}