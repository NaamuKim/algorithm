#include <bits/stdc++.h>
using namespace std;
int n, s, e, et=0;
typedef pair<int,int> pi;
vector<pi> v;

bool cmp(pi a, pi b){
    if(a.second==b.second) return a<b;
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s >> e;
        v.push_back({s,e});
    }
    sort(v.begin(),v.end(),cmp);
    int ret =0;
    for(int i=0; i<v.size(); i++){
        if(et==0||v[i].first>=et){
            et=v[i].second;
            ret++;
        }
    }
    cout << ret <<"\n";
    return 0;
}