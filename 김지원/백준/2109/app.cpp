#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;
int n;
ll ret;
bool cmp(pp a, pp b){
    if(a.second==b.second) return a<b;
    else return  a.second<b.second;
}
int main(){
    cin >> n;
    vector<pp> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<n; i++){
        pq.push(v[i].first);// pq에 일단 push
        // 2개이상 들어갈 시 작은 것은 pop
        if(pq.size()>v[i].second){
            pq.pop();
        }
    }
    while(pq.size()){
        cout << pq.top() <<"\n";
        ret+=pq.top(); 
        pq.pop();
    }
    cout << ret<<"\n";
}