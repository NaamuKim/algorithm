#include <bits/stdc++.h>
using namespace std;
int cnt[26];
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for(char it: s) {
        cnt[it-'a']++;
    }
    for(int i = 0; i<26;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
