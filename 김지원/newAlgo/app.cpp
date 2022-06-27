#include <bits/stdc++.h>
using namespace std;


int foo(int h){
    if(h==0) return 1;
    else if(h==1) return 2;
    int ret =foo(h-1)+foo(h-2);
    return ret;
}

int main(){
    cout << foo(5)<<"\n";
    cout << foo(7)<<"\n";
}