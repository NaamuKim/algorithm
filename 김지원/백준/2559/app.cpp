#include <bits/stdc++.h>

using namespace std;

int n, k;
int ret = -10000004;
int arr[100004];
int psum[100004];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i =1; i<=n; i++){
        cin >> arr[i];
        psum[i]= psum[i-1] + arr[i];
    }
    for(int i=k;i<=n;i++){
        if(psum[i]-psum[i-k]>ret) {
            ret = psum[i]-psum[i-k];
        }
    }
    cout << ret << "\n";
    return 0;
}