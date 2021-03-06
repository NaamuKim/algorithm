#include <bits/stdc++.h>

using namespace std;

int col[16], n;

bool check(int here){
    for(int i =0; i<here; i++){
        if(col[here]==col[i]) return false; // 같은 열에 퀸이 있는지 
        if(abs(col[here]-col[i])==here-i) return false; // 대각선에 퀸이 있는 지
    }
    return true;
}

int solve(int here){
    if(here==n) return 1; //행 배열이 완성돼서 퀸이 다 놓아지면 n에 닿으므로 here==n일 때 1추가
    int ret=0; // 
    for(int row=0; row<n; row++){ //열값을 하나씩 대응시켜보기 
        col[here]=row; // 그 행렬에 퀸은 놔두고
        if(check(here))ret+=solve(here+1); //가능하면 다음 행 시도
        col[here]=-1; 
    } 
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    fill(col,col+16,-1); //행(col)배열에 0이하의 값을 삽입 (즉 0 이하일시 값이 없는 것);
    cout << solve(0) <<"\n"; //재귀함수에 첫줄부터 넣어보기 시작하도록 만든다.
    return 0;
}