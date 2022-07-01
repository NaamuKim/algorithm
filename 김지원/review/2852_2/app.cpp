#include <bits/stdc++.h>
using namespace std;
int n, aScore=0, bScore=0, team;
string _time;
int timeToInt(string s){
    string min = s.substr(0,2);
    string sec = s.substr(3);
    return stoi(min)*60+stoi(sec);
}
string timeStringMake(int time){
    string min = to_string(time/60);
    string sec = to_string(time%60);
    return min+":"+sec;
}
int main(){
    cin >> n;
    pair<int, string> pi;
    for(int i=0; i<n; i++){
        cin >> team>> _time;
        if(aScore>bScore) {
            aScore+=timeToInt(_time)-timeToInt(pi.second);
        } else bScore+=timeToInt(_time)-timeToInt(pi.second);
        pi={team, _time};
        if(team==1) aScore++;
        else bScore++;
    }
    if(aScore>bScore){
        aScore+=timeToInt("48:00")-timeToInt(pi.second);
    } else bScore+=timeToInt("48:00")-timeToInt(pi.second);
    cout << timeStringMake(aScore)<<"\n";
    cout << timeStringMake(bScore)<<"\n";
}