#include <bits/stdc++.h>
using namespace std;
string s;
string a[3]={"pi", "ka", "chu"};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    bool flag = false;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='p'){
            if(s[i+1]!='i') {
                flag=1;
            } else{
                i++;
            }
        } else if(s[i]=='k'){
            if(s[i+1]=='a') i++;
            else flag =1; 
        } else if(s[i]=='c'){
            if(s[i+1]=='h'&& s[i+2]=='u') i+=2;
            else flag =1; 
        } else {
            flag =1;
            break;
        } 
    }
    flag==1 ? cout << "NO" <<"\n" : cout << "YES" <<"\n";
    return 0; 
}