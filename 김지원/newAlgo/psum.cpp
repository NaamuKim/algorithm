#include <bits/stdc++.h>

using namespace std;
int a[100004];
int psum[100004];
int b , c, n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
		cin >> a[i];
        psum[i]=psum[i-1]+a[i];
	}
    for(int i = 0; i < m; i++){
        cin >> b >> c;
        int answer=psum[c]-psum[b-1];
        cout << answer << "\n";
    }
    return 0;

}