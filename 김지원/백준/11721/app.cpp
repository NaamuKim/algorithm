#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;

int main(){
    string ret;
    getline(cin, s);
    for(int i =0; i< s.size(); i+=10){
        for(int j=0; j<10; j++){
            ret+=s[i+j];
        }
        cout << ret <<"\n";
        ret="";
    }
    return 0;
}