#include <bits/stdc++.h>

using namespace std;

const int MAX=200001;
int n, k,ret,now;
int dist[MAX],_prev[MAX];
queue<int>q;
vector<int> v;
int main(){
    cin >> n >>k;
    dist[n]=1;
    q.push(n);
    while(q.size()){
        now = q.front();
        q.pop();
        if(now==k){
            ret=dist[k];
            break;
        }
        for(int next:{now-1, now+1, now*2}){
            if(next >= MAX || next < 0 || dist[next]) continue; 
                    dist[next]=dist[now]+1;
                    _prev[next]=now;
                    q.push(next);
                }
    }
        cout << ret-1 <<"\n";
        for(int i =k; i!=n; i=_prev[i]){
            v.push_back(i);
        }
        v.push_back(n);
        reverse(v.begin(), v.end());
        for(int i =0; i<v.size(); i++){
            cout << v[i] <<" ";
        }
        return 0;
}