#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    getline(cin, s); 
    for(char it: s){
        if(it>=65 && it<=90){
            if(it+13>90) it= it - 13;
            else it += 13;
        } else if(it>=97 && it<=122){
            if(it+13>122) it= it -13;
            else it+=13;
        }
        cout << it;
    }
}