#include <bits/stdc++.h>

using namespace std;

int t, n, m, x;


int main(){
    cin >>t;
    for(int i =0; i<t; i++){
        vector<int> v;
        queue<pair<int,int>> q;
        int cnt =0;
        cin >> n >> m;
        for(int j =0; j<n; j++){
            cin >>x;
            v.push_back(x);
            if(j==m) q.push({x,1});
            else q.push({x,0});
        }
        sort(v.begin(), v.end());
        while(true){
            if(v.back()==q.front().first){
                if(q.front().second==1){
                    cnt++; 
                    break;
                }else {
                    v.pop_back();
                    q.pop();
                    cnt++;
                }
            } else{
                q.push({q.front().first,q.front().second}); 
                q.pop();
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}
