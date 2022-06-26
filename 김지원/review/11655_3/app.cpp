#include <bits/stdc++.h>
using namespace std;
string s, answer;
int main(){
    getline(cin,s);
    for(char it: s){
        if(it>=65&&it<=90){
            if(it+13>90) answer+=it-13;
            else answer+=it+13;
        } else if(it>=97&&it<=122){
            if(it+13>122) answer+=it-13;
            else answer+=it+13;
        } else answer+=it;
    }
    cout << answer <<"\n";
    return 0;
}