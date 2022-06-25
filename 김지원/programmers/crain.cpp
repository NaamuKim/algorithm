#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n =board[0].size();
    stack<int> stk;
    for(int it: moves){
        for(int i=0; i<n; i++){
            if(board[i][it-1]==0) continue;
            if(stk.size()&&stk.top()==board[i][it-1]){
                stk.pop();
                answer+=2;
                board[i][it-1]=0;
                break;
            } else {
                stk.push(board[i][it-1]);
                board[i][it-1]=0;
                break;
            }
        }
        cout <<"\n";
    }
    return answer;
}