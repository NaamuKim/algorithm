#include <bits/stdc++.h>

using namespace std;

int x,ret=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> x;
    while(x!=1){
        if(x&1) ret++; //2로나눴을 떄 나머지가 있는 거 찾기 == 비트 찾기
        x/=2;
    }
    cout << ret <<"\n";
    return 0;
}