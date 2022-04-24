#include <bits/stdc++.h>

using namespace std;

int n, k, a[100004], cnt=1;
string s;
stack<int> stk;

int main(){
    cin >>n;
    for(int i =0; i<n; i++){
        cin >> a[i];
        while(a[i]>=cnt){
            stk.push(cnt);
            cnt++;
            s+="+\n";
        }
                if(stk.top()==a[i]){
                    stk.pop();
                    s+="-\n";
                }
                else{
                    s="NO";
                    break;
                } 
            }
    cout << s;
    return 0;
}