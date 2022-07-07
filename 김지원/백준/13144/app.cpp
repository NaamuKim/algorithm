#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
long long s, e, cnt[100001], n, a[100001];
long long ret;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    while(e<n){
        if(!cnt[a[e]]){
            cnt[a[e]]++;
            e++;
        }else{
            ret+=(e-s);
            cnt[a[s]]--;
            s++;
        }
    }
    ret+=(long long)(e-s)*(e-s+1)/2;
    cout << ret <<"\n";
    return 0;
}