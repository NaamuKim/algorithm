#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    cin >> n;
    vector<pair<ll,ll>> v(n); 
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<n; i++){
        pq.push(v[i].second);
        if(pq.size()>v[i].first){
            pq.pop();
        }
    }
    ll ret =0;
    while(pq.size()){
        ret+=pq.top();
        pq.pop();
    }
    cout << ret <<"\n";
    return 0;
}