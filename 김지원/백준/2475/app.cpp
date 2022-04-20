#include <bits/stdc++.h>

using namespace std;

int a[6],ret;
int sum=0;

int main(){
    for(int i =0; i<5; i++){
        cin >>a[i];
        sum+=(a[i]*a[i]);
    }
    ret=sum%10;
    cout << ret;
    return 0;
}