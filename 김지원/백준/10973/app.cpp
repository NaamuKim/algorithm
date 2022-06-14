#include <bits/stdc++.h>
using namespace std;
vector<int> v, cp;
int n, in;
bool flag;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> in;
        v.push_back(in);
    }
    cp.resize((int)(v.size()));
    copy( v.begin(), v.end(), cp.begin() );
    sort( cp.begin(), cp.end());
    for(int i=0; i<v.size(); i++){
        if(v[i]!=cp[i]) flag =true;
    }
    if(!flag) {
        cout <<-1<<"\n";
        return 0;
    }
    prev_permutation(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
    return 0;
}