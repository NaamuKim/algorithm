#include <bits/stdc++.h>

using namespace std;

int x, y;
string d[7]={"SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cnt =0;
int main(){
    cin >> x >> y;
    for(int i =0; i<x; i++){
        if((i+1)==x){
            cnt+=y;
        } else{
            cnt+= month[i];
        }
    }
    cout << d[cnt%7] <<"\n";
    return 0;
}