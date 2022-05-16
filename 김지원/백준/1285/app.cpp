#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;   
int n, ret=INF;
int a[21];
string s;

void go(int here){
    if(here==n+1){
        int sum =0;
        for(int i=1; i<=(1<<(n-1)); i*=2){ //한 열씩
            int cnt =0; 
            for(int j=1; j<=n; j++) if(a[j]&i) cnt++; //행마다 비트 차있으면 cnt++;
            sum+=min(cnt, n-cnt);
        }
        ret=min(ret,sum);
        return;
    }
    a[here]=~a[here];
    go(here+1); //행을 뒤집고 한번
    a[here]=~a[here]; //행을 안 뒤집고 한 번
    go(here+1);
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s;
        int value = 1;
        for(int j =0; j<n; j++){
            if(s[j]=='T') a[i]|=value; //이미 있는 곳 제외하고 비트 채우기
            value*=2;
        }
    }
    // for(int i =1; i<=n; i++) cout << a[i] <<"\n";
    go(1);
    cout << ret <<"\n";
    return 0;
}   