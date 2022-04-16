#include <bits/stdc++.h>
using namespace std;

int n, m, 1m, 2m, 1s, 2s, team,fteam;
string time, ftime;

int main(){
    cin >>n;
    cin >> fteam >> ftime;
    for(int i =0; i<n-1; i++){
        cin >> team >> time;
        if(team==1){
            1m+=int(time[0])*10+int(time[1]);
            1s+=int(time[3])*10+int(time[4]);
        }else{
            2m+=int(time[0])*10+int(time[1]);
            2s+=int(time[3])*10+int(time[4]);
        }
    }
}