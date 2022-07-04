#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
vector<pi> v;
ll n, k, ret;
int main(){
    cin >> n >> k; 
	vector<pi> v(n);
	vector<ll> vv(k); 
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i=0; i<k; i++){
        cin >>vv[i]; 
    }
    sort(v.begin(),v.end());
    sort(vv.begin(),vv.end());
    int j=0;
    priority_queue<ll> pq;
    for(int i=0; i<k; i++){
        while(j<n&&v[j].first<=vv[i]) pq.push(v[j++].second);
        if(pq.size()){
            ret+=pq.top(); pq.pop();
        }
    }
    cout << ret <<"\n";
    return 0;
}