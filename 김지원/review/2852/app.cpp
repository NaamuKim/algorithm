#include <bits/stdc++.h>

using namespace std;
#define prev naamukim
int a, b, t,n, asum, bsum;
string s, prev;

string print(int a){ 
    string d = "00" + to_string(a / 60); 
    string e = "00" + to_string(a % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

int changeToInt(string s){
    return atoi(s.substr(0,2).c_str())*60+atoi(s.substr(3).c_str());
}

void go(int &sum, string s){
    sum+=(changeToInt(s)-changeToInt(prev));
}

int main(){
    cin >>n;
    for(int i =0; i<n; i++){
        cin >> t >> s;
        if(a>b) go(asum,s);
        if(b>a) go(bsum,s);
        t==1 ? a++ : b++;
        prev=s;
    }
    if(a>b) go(asum, "48:00");
    if(b>a) go(bsum, "48:00");
    cout << print(asum) <<"\n";
    cout << print(bsum) <<"\n";
}