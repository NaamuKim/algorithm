#include <bits/stdc++.h>
using namespace std;
int n, m, b, tim=987654321, h, maxi=0, mini=257, a[501][501], r=0,tmp;

bool canBlock(int r){
    int newB=b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]<r){
                newB-=(r-a[i][j]);
                if(newB<0) return false;
            }
        }
    }
    return true;
}
int main(){
    cin >> n >> m >> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            mini=min(mini,a[i][j]);
            maxi=max(maxi,a[i][j]);
        }
    }
    //블록 여유 판별
    r=maxi;
    while(r>-1){
        tmp=0;
        if(canBlock(r)){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(a[i][j]<r){
                        tmp+=(r-a[i][j]);
                    } else if(a[i][j]>r){
                        tmp+=2*(a[i][j]-r);
                    }
                }
            }
            if(tmp<tim){
                tim=tmp;
                h=r;
            }
        }
        r--;
    }

    cout << tim<< " " << h <<"\n";
    return 0;
}
