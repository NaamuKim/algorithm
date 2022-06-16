#include <bits/stdc++.h>
using namespace std;
string s;
string answer;
int main(){
    getline(cin,s);
    for(char it: s){
        if((it>75&&it<91)||(it>108&&it<123)){
            answer+=(it-15);
        } else if((it>=65&&it<=75)||(it>=97&&it<=108)){
            answer+=(it+15);
        } else answer+=it;
    }
    cout << answer;
}