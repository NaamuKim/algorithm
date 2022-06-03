#include <bits/stdc++.h>

using namespace std;

int n,k;
const int MAX=100000;
int dist[MAX+1];
long long cnt[MAX+1];

queue<int> q;
int main(){
    cin >> n >> k;
    if(n == k){
        puts("0"); puts("1");
        return 0; 
    }  
    dist[n]=0;
    cnt[n]=1;
    q.push(n);
    while(q.size()){
        int now = q.front(); 
        q.pop();
        for(int next: {now-1, now+1, now*2}) {
            if(0 <= next && next <= MAX){
                if(!dist[next]){
                    q.push(next);
                    dist[next]=dist[now]+1;
                    cnt[next]+=cnt[now];
                } else if(dist[next]==dist[now]+1){
                    cnt[next]+=cnt[now];
                };
            }
        }
    }
    cout << dist[k] <<"\n";
    cout << cnt[k] << "\n";
    return 0;
}