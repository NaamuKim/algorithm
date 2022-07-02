#include <bits/stdc++.h>
using namespace std;
int cnt[30];
string s;
bool isVowel(int idx){
    if(idx==0||idx==4||idx==8||idx==14||idx==20) return true;
    return false;
}
int main(){
    while(true){
        cin >> s;
        if(s=="end") break;
        fill(&cnt[0],&cnt[0]+30,0);
        int lcnt =0, vcnt=0;
        int flag =0;
        for(int i=0; i<s.size(); i++){
            int idx=s[i]-'a';
            cnt[idx]++;
            if(isVowel(idx)){
                vcnt++;
                lcnt=0;
            }else{
                vcnt=0;
                lcnt++;
            }
            if(lcnt>=3||vcnt>=3) flag=1;
            if(i!=0&&(s[i-1]==s[i])&&(idx!=4&&idx!=14)) flag=1;
        }
        if(cnt[0]==0&&cnt[4]==0&&cnt[8]==0&&cnt[14]==0&&cnt[18]==0) flag=1;
        cout << "<"<<s<<"> ";
        flag ? cout<<"is not acceptable.\n"  :cout<<"is acceptable.\n";
    }
    return 0;
}