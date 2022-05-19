#include <bits/stdc++.h>

using namespace std;

int x;
int main(){
    cin >> x;
    int stickSum=64;
    vector<int> stick;
    stick.push_back(64);
    while(stickSum>x){
        sort(stick.begin(), stick.end());
        int temp=stick[0]/2;
        if(stickSum-temp>=x){
            stick[0]/=2;        
            stickSum-=temp;
        }
        else {
            stick.push_back(temp);
            stick[0]/=2;
        }
    }
    cout << stick.size()<<"\n";
    return 0;
}