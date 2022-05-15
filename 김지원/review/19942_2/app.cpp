#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
int n,mp,mf,ms,mv,b,c,d,e,sum,ret=INF;

struct n{
    int p, f, s, v, cost;
} a[16];

map<int,vector<vector<int>>> ret_v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >>ms >>mv;
    for(int i =0; i<n; i++){
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >>a[i].cost;
    }
    for(int i =1; i<=(1<<n); i++){
        vector<int> v;
        b=c=d=e=sum=0;
        for(int j =0; j<n; j++){
            if(i&(1<<j)){
                v.push_back(j+1);
                b+=a[j].p;
                c+=a[j].f;
                d+=a[j].s;
                e+=a[j].v;
                sum+=a[j].cost;
            }
        }
        if(b>=mp && c>=mf && d>=ms && e>=mv &&sum<=ret){
            ret=sum;
            ret_v[ret].push_back(v);
        }
    }
    sort(ret_v[ret].begin(), ret_v[ret].end());
    if(ret==INF) cout << -1 <<"\n";
    else {
        cout << ret <<"\n";
        for(int item : ret_v[ret][0]) cout << item <<" ";
    }
    return 0;
}