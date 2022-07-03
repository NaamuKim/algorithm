#include <bits/stdc++.h>
using namespace std;
int n, asum, bsum;
#define prev naamukim
int team;
string _time, prev;

string print(int sum){
    string d = "00"+to_string(sum/60);
    string e = "00"+to_string(sum%60);
    return d.substr(d.size()-2,2)+":"+e.substr(e.size()-2,2);
}

int changeToInt(string s){
    return atoi(s.substr(0,2).c_str())*60+atoi(s.substr(3).c_str());
}

void go(int &sum, string s){
    sum+=changeToInt(s)-changeToInt(prev);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int a=0, b=0;
    for(int i=0; i<n; i++){
        cin >> team >>_time;
        if(a>b) go(asum, _time);
        if(b>a) go(bsum, _time);
        team==1 ? a++ :b++;
        prev=_time;
    }
    if(a>b) go(asum,"48:00");
    if(b>a) go(bsum,"48:00");
    cout << print(asum) <<"\n";
    cout << print(bsum) <<"\n";
    return 0;
}