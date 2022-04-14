#include <bits/stdc++.h>

using namespace std;
int a[300];

int sum = 0;

int main() {
    for(int i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 9; j++){
            if(sum-(a[i]+a[j])==100) {
                a[i]=0;
                a[j]=0;
                break;
            }
        }
    }
    sort(a, a+9);
    for(int it: a) {
        if(it!=0){
            cout << it << "\n";
        }
    }
    return 0;
}