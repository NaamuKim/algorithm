#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;  
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
vector<int> adj[11]; 


pair<int, int> dfs(int here, int value){
    visited[here] = 1; 
    pair<int, int> ret = {1, a[here]}; 
    for(int there : adj[here]){
        if(comp[there] != value) continue; //다른 군이 가지고 있는 거면 continue 
        if(visited[there]) continue; //방문했으면 continue
        pair<int, int> _temp = dfs(there, value); 
        ret.first += _temp.first; 
        ret.second += _temp.second;  
    }
    return ret; 
}  

int main(){
    cin >> n;
    for(int i =1; i<=n; i++){ //비트 마스킹을 사용하는 데에 용이하도록 1부터 넣어주기
        cin >> a[i]; 
    }
    for(int i = 1; i <= n; i++){
        cin >> m; 
        for(int j = 0; j < m; j++){
            cin >> temp; 
            adj[i].push_back(temp); //양방향
            adj[temp].push_back(i); 
        } 
    }
    for(int i = 1; i < (1 << n) - 1; i++){ //결국은 비트를 이용한 완전탐색(트리를 for문으로 어떻게 구현할까에 대한 답)
        fill(comp, comp + 11, 0); //모든 경우이므로 할떄마다 초기화
        fill(visited, visited + 11, 0); 
        int idx1 = -1, idx2 = -1; 
        for(int j = 0; j < n; j++){
            //idx번쨰 비트가 있는지 확인하여 있으면 첫버내 군단에 추가
            if(i & (1 << j)){
                comp[j + 1] = 1; idx1 = j + 1;
            }
            else idx2 = j + 1; 
        }
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);   
        if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second)); 
    } 
    cout << (ret == INF ? -1 : ret)<< "\n";
}