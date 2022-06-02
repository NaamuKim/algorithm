#include <bits/stdc++.h>
using namespace std;
string s;
int n,m;
int main(){
    cin >> n;
    deque<int> deq;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s.substr(0,4)=="push"){
            cin >> m;
            if(s[5]=='b') deq.push_back(m);
            else deq.push_front(m);
        }
        else if(s.substr(0,3)=="pop"){
            if(deq.size()){
                if(s[4]=='b') {
                    cout << deq.back()<<"\n";
                    deq.pop_back();
                }
                else {
                    cout << deq.front()<<"\n";
                    deq.pop_front();
                }
            } else cout << -1 <<"\n";
        }       
        else if(s[0]=='s') cout<<deq.size()<<"\n";
        else if(s[0]=='e') deq.size() ? cout << 0 <<"\n" : cout << 1 <<"\n";
        else if(s[0]=='f') deq.size()!=0 ? cout << deq.front() <<"\n" : cout << -1 <<"\n";
        else if(s[0]=='b') deq.size()!=0 ? cout << deq.back() <<"\n" : cout << -1 <<"\n";
    }
    return 0;
}