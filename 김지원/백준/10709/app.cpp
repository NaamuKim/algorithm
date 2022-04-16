#include <bits/stdc++.h>
using namespace std;

int h, w;
char a[104][104];
int b[104][104];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w;
    for(int i =0; i <h; i++){
        for(int j =0; j<w;j++){
            cin >> a[i][j];
        }
    }
    for(int i =0; i <h; i++){
        for(int j =0; j<w;j++){
            b[i][j]=-1;
            if(a[i][j]=='c') b[i][j]=0;
            else{
                for(int k =0; k<j; k++){
                    if(a[i][k]=='c') b[i][j]=(j-k);
                }
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j =0; j<w; j++){
            cout << b[i][j] << " ";
        }
        cout <<"\n";
    }
}