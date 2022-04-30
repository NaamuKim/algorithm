#include <bits/stdc++.h>

using namespace std;

int n,k,vis[100004];
const int MAX=100000;
struct A{
    int a, b, c;
}
queue<int> q;
int main(){
    cin >> n >> k;
    vis[n]=1;
    q.push(n);
    while(q.size()){
        int a = q.front();
        q.pop();
        for(int next: {a-1, a+1, a*2}) {
            if(0 <= next && next <= MAX){
                if(!vis[next]){
                    q.push(next);
                    vis[next]=vis[n]+1;
                }
            }
        }
    }
    cout << vis[k]-1 <<"\n";
    cout 
}