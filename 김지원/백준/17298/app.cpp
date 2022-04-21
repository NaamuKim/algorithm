#include <bits/stdc++.h>

using namespace std;
int a[1000004], n;
stack<int> s;
int ret[1000004];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i= 0; i<n; i++){
        cin >>a[i];
        while(s.size() && a[i]>a[s.top()]){
            ret[s.top()]=a[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i =0; i<n; i++){
        if(ret[i]==0) cout << -1 << " ";
        else cout << ret[i] <<" ";
    }
}