#include <iostream>
#include <stack>

using namespace std;
stack<string> stk;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    stk.push("엄");
    stk.push("준");
    stk.push("식");
    stk.push("이");
    stk.push("름");
    stk.push("이");
    while(stk.size()){
        cout << stk.top() << "\n";
        stk.pop();
    }
return 0;
}