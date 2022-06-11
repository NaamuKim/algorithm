#include <bits/stdc++.h>
using namespace std;
string a, b;
int ret=987654321;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    int num= b.size()-a.size();
    for(int j=0; j<=num; j++ ){
        int cnt =0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i+j]) cnt++;
        }
        ret=min(ret,cnt);
    }

    cout << ret <<"\n";
    return 0;
}
