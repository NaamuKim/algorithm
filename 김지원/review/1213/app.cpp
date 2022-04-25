#include <bits/stdc++.h>

using namespace std;

string s,ret;
int cnt[i];
int flag=0;
int main(){
    getline(cin, s);
    for(int i =0; i<s.size();i++){
        cnt[s[i]]++;
    }
    for(char i ='A'; i<'Z'; i++){
        if(cnt[i]%2==1){
            flag++;
        }
        else{
            for(int i =0; i<cnt[i]; i+=2){
                ret=i+ret;
                ret=ret+i;
            }
        }
    }
}