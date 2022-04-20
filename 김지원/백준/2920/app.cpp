#include <bits/stdc++.h>

using namespace std;

int a[10];

int main(){
    int as=0;
    int de=0;
    for(int i =0; i<8; i++){
        cin >>a[i];
        if(a[i]==i+1) as++;
        else if(a[i]==8-i) de++;
    }
    if(as==8) cout << "ascending";
    else if(de==8) cout << "decending";
    else cout << "mixed";
    return 0;
}