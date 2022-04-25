#include <bits/stdc++.h>

using namespace std;
int n, m;
string a[51];
int ret=64;
string wb[8] ={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string bw[8]={
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int search(int y, int x){
    int cnt=0, cnt2=0;
    for(int i =0; i<8; i++){
        for(int j =0; j<8; j++){
            if(a[y+i][x+j]!=wb[i][j]) cnt++;
            if(a[y+i][x+j]!=bw[i][j]) cnt2++;
        }
    }
    return min(cnt, cnt2);
}

int main(){
    cin >> n >> m;
    for(int i =0; i<n; i++){
        cin >> a[i];
    }

    for(int i =0; i+8<=n; i++){
        for(int j=0; j+8<=m; j++){
            // 8*8탐색
            int mn = search(i,j);
            ret=min(ret,mn);
        }
    }
    cout << ret <<"\n";
}