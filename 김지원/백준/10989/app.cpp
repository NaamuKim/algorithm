#include <bits/stdc++.h>
using namespace std;
int n,input,a[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> input;
        a[input]++;
    }
    for(int i=0; i<10001; i++){
        for(int j=0; j<a[i]; j++){
            cout << i<<"\n";
        }
    }
    return 0;
}