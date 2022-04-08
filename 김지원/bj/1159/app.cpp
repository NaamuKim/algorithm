#include <bits/stdc++.h>

using namespace std;
string s;
int cnt[29];
int n;
bool flag = false;
int main(){
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> s;
        cnt[s[0]-'a']++;
    }
    for(int i=0; i< 29; i++){
        if(cnt[i]>=5) {
            flag=true;
            cout << char(i+'a');
        }
    }
    if(flag==false) cout << "PREDAJA";
}