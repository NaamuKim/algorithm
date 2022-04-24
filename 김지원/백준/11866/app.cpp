#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int n, k;
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i =0; i<n; i++) q.push(i+1);
    while(q.size()){
        for(int i =0; i<k-1; i++) {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for(int i=0; i<v.size(); i++){
        if(i==v.size()-1) cout <<v[i];
        else cout <<v[i] << "," <<" ";
    }
    cout <<">";
}