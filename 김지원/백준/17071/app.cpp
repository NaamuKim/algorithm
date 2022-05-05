#include <bits/stdc++.h>

using namespace std;

const int MAX=500000;
int vis[2][MAX+1];
int n, k, turn=1, ret;
bool flag;
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    if(n == k) {
        cout << 0 <<"\n";
        return 0;
    } 
    vis[0][n]=1;//0은 수빈이 위치 배열
    q.push(n); //큐에 시작접을 넣어줌
    while(q.size()){
        k+=turn;
        if(k>MAX) break;// 동생이 범위를 넘어가면 break;
        if(vis[turn%2][k]){ //턴수의 홀짝이 같은 배열에 값이 있다. 즉 수빈이가 그곳을 들렸다. 홀짝이 다르면 아직 만날 수 없다.
            flag = true;
            break;
        }   
        int qSize=q.size(); //최단거리가 같은 레벨을 묶어서 봐야한다.
        for(int i=0; i<qSize; i++){ //레벨 하나씩 다 살펴보자
            int here = q.front(); //큐의 맨 앞을 현지점이라고 놓고
            q.pop(); //꺼낸다.
            for(int next: {here-1, here+1, here*2}){
                // 범위를 넘어섰거나 이미 들렸던 지점이면(예전에 들렸던 게 최단거리일것이다.) 다음으로 넘어간다.
                if(next<0 || next >MAX ||vis[turn%2][next]) continue;
                //수빈이가 홀수번째면 짝수번쨰로 간곳에다가 지점에다가 1더하고 짝수번쨰면 홀수번쨰로 간 지점에다가 1 더한다.
                //홀짝 판별 이유는 수빈이 이동 경우의수 중에 +1, -1이 있기 떄문에 특정 지점일 때 짝수번쨰만큼 차이가 나면 다시 가면 된다.
                //그래서 간 지점이 짝수번짼지 홀수 번짼지를 기록하는 것
                vis[turn%2][next]=vis[(turn+1)%2][here]+1;
                //수빈이가 간 지점에 동생이 있는 지 확인하자
                if(next == k) {
                    flag=1;
                    break;
                }
                //안 끝났다면 다음 지점을 기준으로 시작할 수 있게끔 큐에다가 넣어주자.
                q.push(next);
            }
        }
        if(flag) break;
        turn++;
    }
    if(flag) cout << turn <<"\n";
    else cout << -1 <<"\n";
    return 0;
}
