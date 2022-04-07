#include <bits/stdc++.h>

using namespace std;
int a, b, c, start, last;
int cnt[100];
int main(){
    int result = 0;
    cin >> a >> b >> c;
    for(int i=1; i<=3;i++){
        cin >> start >> last;
        for(int j = start; j<last;j++){
            cnt[j]++;
        }
    }
    for(int it: cnt){
        if(it==1) result += a * it;
        else if(it==2) result += b * it;
        else if(it==3) result += c* it;
    }
    cout << result << endl;
}
