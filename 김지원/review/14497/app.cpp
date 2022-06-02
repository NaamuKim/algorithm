#include <bits/stdc++.h>

using namespace std;

int _x1,_y1,_x2,_y2,x,y,n,m;
char a[304][304];
int dy[4]={0, 1, 0, -1};
int dx[4]={1, 0, -1 ,0};
int vis[304][304];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> _y1 >> _x1 >> _y2 >> _x2;
    _x1--; _y1--; _x2--; _y2--;
    q.push(1000*_y1+_x1); //1차원으로 바꿔서 생각해보자
    vis[_y1][_x1]=1; //시작하는 거 비지티드 걸기
    for(int i = 0; i < n; i++){
        cin >>a[i];
    }  
    int cnt =0;
    while(a[_y2][_x2]!='0'){ // 범인이 잡히면 종결
        cnt++; // 하위 while문에서 bfs가 끝나고(1을 만나서) 퍼지다 1 만났으니 cnt++
        queue<int> temp; //장애물 만나면 담기는 큐 큰 while문 돌떄마다 초기화
        while(q.size()){ // 0을 만나면
            y = q.front()/1000; // 1차원으로 바꿔서 push했으니 다시 좌표를 꺼내자
            x = q.front()%1000;
            q.pop(); //쓴 값은 버리고
            for(int i =0; i<4; i++){ 
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(ny<0 || ny>=n || nx<0 || nx>=m ||vis[ny][nx]) continue;
                vis[ny][nx]=cnt; //얼마나 걸리는 지 담기
                if(a[ny][nx]!='0'){ // 사람이거나 범인이면
                    a[ny][nx] = '0'; //0으로 바꾸자
                    temp.push(1000 * ny + nx); //장애물 큐에 넣어주기
                }else q.push(1000*ny+nx); //비어있는 곳에 넣어주기
            }
        }
        q=temp; //빈 큐에 장애물들을 쭉 넣어주기 하위 while문이 돌아가기 위해
    }    
    cout << vis[_y2][_x2] <<"\n";
    return 0;
}