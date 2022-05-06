#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std; 
char a[301][301];
int n, m, x1, y1, x2, y2; 
typedef pair<int, int> pi;
int visited[301][301];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int ret; 
queue<int> q;
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--, x1--, y2--, x2--; //a 배열은 0부터 넣었음
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]); 
    }  
    q.push(1000 * y1 + x1); // 2차원을 1차원으로(나중에 모듈러로 2개로 만들 수 있음)
    visited[y1][x1] = 1; 
    int cnt = 0; 
    while(a[y2][x2] != '0'){  //훔친 사람이 죽을 떄까지
        cnt++; 
        queue<int> temp; 
        while(q.size()){
            int y = q.front() / 1000; //숫자를 2차원으로 쪼개기 몫은 y
            int x = q.front() % 1000;  //나머지는 x
            q.pop();  
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i]; 
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue; 
                visited[ny][nx] = cnt;  
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0'; 
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000 * ny + nx); 
            }
        }
        q = temp;  
    }
    printf("%d\n", visited[y2][x2]); 
}