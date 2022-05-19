#include <bits/stdc++.h>

using namespace std;

int n,k,words[54];
string s;
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<s.size(); j++){
            words[i]|=(1<<(s[j]-'a'));
        }
        cout << words[i]<<"\n";
    }
    
}