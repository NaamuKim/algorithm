#include <bits/stdc++.h>

using namespace std;

const int _MAX=100001;
int n,k,visited[1000001],nx;
queue<int> q;

void bfs(int x){
    q.push(x);
    while(q.size()){
        x=q.front();
        if(x==k) break;
        q.pop();
        nx=x+1;
        if(visited[nx]==0 && nx>=0 && nx<_MAX){
            visited[nx]=visited[x]+1;
            q.push(nx);
        }  
        nx= x-1;
        if(visited[nx]==0 && nx>=0 && nx<_MAX){
            visited[nx]=visited[x]+1;
            q.push(nx);
        }
        nx= 2*x;  
        if(visited[nx]==0 && nx>=0 && nx<_MAX){
            visited[nx]=visited[x]+1;
            q.push(nx);
        }
    }
}

int main(){
    cin >>n >>k;
    visited[n]=0;
    bfs(n);
    cout << visited[k] <<"\n";
    return 0;
}
