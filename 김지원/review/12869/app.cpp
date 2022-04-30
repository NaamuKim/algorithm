#include <bits/stdc++.h>

using namespace std;
int n, a[3], vis[104][104][104];
int _a[6][3]={{9, 3, 1},{9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3}};
struct A{
    int a,b,c;
};
queue<A> q;
int main(){
    cin >>n; 
    for(int i =0; i<n; i++){
        cin >>a[i];
    } 
    vis[a[0]][a[1]][a[2]] = 1; 
    q.push({a[0],a[1],a[2]});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(vis[0][0][0])break;
        for(int i =0; i<6; i++){
            int na = max(0, a-_a[i][0]);
            int nb = max(0, b-_a[i][1]);
            int nc = max(0, c-_a[i][2]);
            if(vis[na][nb][nc])continue;
            vis[na][nb][nc] =vis[a][b][c]+1;
            q.push({na,nb,nc});
        }
    }
    cout << vis[0][0][0]-1 <<"\n";
    return 0;
}