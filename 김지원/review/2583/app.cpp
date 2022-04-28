#include <string>
#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std;

int n, m, k, x1, y1, x2, y2,_map[101][101],vis[101][101], cnt;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

vector<int> v;
int dfs(int y, int x){
    _map[y][x]=1;
    int ret =1;
    for(int i =0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m ||_map[ny][nx]) continue;
        ret+=dfs(ny, nx);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n>> m>> k;
    for(int i =0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i =y1; i<y2; i++){
            for(int j = x1; j <x2; j++){
                _map[i][j]=1;
            }
        }
    }
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(!_map[i][j]) v.push_back(dfs(i,j));
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() <<"\n";
    for(int item : v) cout << item << " ";
}