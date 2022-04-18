#include <bits/stdc++.h>

using namespace std;

string n,s;

int main(){
    while(true){
        cin >> n;
        if(n=="0") return 0;
        s=n;
        reverse(n.begin(), n.end());
        if(n==s) cout << "yes" <<"\n";
        else cout <<"no"<< "\n"; 
    }
    return 0;
}