#include <bits/stdc++.h>
using namespace std;
int n, k, a[101], vis[101],cnt;
vector<int> v;
const int INF=987654321;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<k; i++) cin >> a[i];
    for(int i=0; i<k; i++){
        if(!vis[a[i]]){
            if(v.size()==n){
                int last_idx=0, pos;
                for(int _a: v){
                    int here_pick=INF;
                    for(int j=i+1; j<k; j++){
                        if(_a==a[j]){
                            here_pick=j;
                            break;
                        }
                    }
                    if(last_idx<here_pick){
                        last_idx=here_pick;
                        pos=_a;
                    }
                }
                vis[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(a[i]);vis[a[i]]=1;
        }

    }
    cout << cnt <<"\n";
    return 0;
}