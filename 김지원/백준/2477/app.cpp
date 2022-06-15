#include <bits/stdc++.h>
using namespace std;
int n, ret, w=1;
pair<int, int> a[6];
int solution(){
    for (int i=0; i<6; i++){
        int cur=a[i].second*a[(i+1)%6].second;
        if(w==1||cur>w){
            w=cur;
            ret=(w-a[(i+3)%6].second*a[(i+4)%6].second)*n;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<6; i++){
        cin >> a[i].first >> a[i].second;
    }

    cout << solution() <<"\n";
    return 0;
}
