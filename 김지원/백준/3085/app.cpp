#include <bits/stdc++.h>
using namespace std;
int n,ret;
char a[51][51];
void check(){
    char c;
    for(int i=0; i<n; i++){
        int count =1;
        c = a[i][0];
        for(int j=1; j<n; j++){
            if(a[i][j]==c){
                count++;
            } else{
                c=a[i][j];
                count=1;
            }
            ret=max(count,ret);
        }

    }
    for(int j=0; j<n; j++){
        int count =1;
        c=a[0][j];
        for(int i=1; i<n; i++){
            if(a[i][j]==c){
                count+=1;
            }else {
                count =1;
            }
            c=a[i][j];
            ret=max(count,ret);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            swap(a[i][j], a[i][j+1]);
            check();
            swap(a[i][j+1], a[i][j]);
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            swap(a[i][j], a[i+1][j]);
            check();
            swap(a[i+1][j], a[i][j]);
        }
    }
    cout << ret << "\n";
    return 0;
}
