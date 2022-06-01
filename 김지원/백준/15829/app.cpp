#include <bits/stdc++.h>
using namespace std;
int n;
string s;
const int M=1234567891;
int main(){
    cin >> n;
    long long sum=0;
    long long r=1;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        sum=(sum+(s[i]-96)*r)%M;
        r=(r*31)%M;
    }
    cout <<sum<<"\n";
    return 0;
}