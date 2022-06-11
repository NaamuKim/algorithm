#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[26];
int main(){
    ios_base::sync_with_stdio(0); cout.tie(NULL);
    cin >> s;
    for(char it: s){
        cnt[it-'a']++;
    }
    for(int i=0; i<26; i++){
        cout << cnt[i] <<" ";
    }
    return 0;
}