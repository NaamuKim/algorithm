#include <bits/stdc++.h>
using namespace std;
int n,c,in;
vector<int> v;
map<int, int> cnt, first;

bool cmp(int a, int b){
    if(cnt[a]==cnt[b]) return first[a]<first[b];
    else return cnt[a]>cnt[b];
}

int main(){
    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> in;
        v.push_back(in);
        cnt[in]++;
        if(!first[in])first[in]=i;
    }
    sort(v.begin(), v.end(), cmp);
    for(int it: v) cout << it <<" ";
}