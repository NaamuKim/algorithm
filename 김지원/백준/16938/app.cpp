#include <bits/stdc++.h>

using namespace std;
int a[300];
int n, l, r, x;
int ans = 0;

int main() {
    cin >> n >> l >> r >> x;
    for(int i =0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<(1<<n); i++){
        int ml=2e9, mr=0, sum=0, cnt=0;
        for(int j=0;j<n;j++){
            if((i&(1<<j))>0){
                mr=max(mr,a[j]);
                ml=min(ml,a[j]);
                sum+=a[j];
                cnt++;
            }
        }
        if(cnt>=2 && sum<=r && sum>=l && mr-ml>=x) ans++;
    }
    cout << ans << "\n";
    return 0;
}

