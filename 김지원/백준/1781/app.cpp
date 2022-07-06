#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
int n, a, b;
ll ret;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pp> v;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<n; i++){
        pq.push(v[i].second);
        if(pq.size()>v[i].first) pq.pop();
    }
    while(pq.size()){
        ret+=pq.top();
        pq.pop();
    }
    cout << ret <<"\n";
    return 0;
}