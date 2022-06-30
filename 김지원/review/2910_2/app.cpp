#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

int n, c;
int a[1004];
map<int, int> _map, first;

bool cmp(pp &a, pp &b){
    if(a.second==b.second){
        return first[a.first]<first[b.first];
    }
    return a.second>b.second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for(int i =0; i<n; i++){
        cin >> a[i];
        _map[a[i]]++;
        if(first[a[i]]==0) first[a[i]]=i+1;
    }
    vector<pp> vec(_map.begin(), _map.end());
    sort(vec.begin(), vec.end(), cmp);
    for(auto item: vec){
        for(int i=0; i<item.second; i++){
            cout <<item.first<<" ";
        }
    }
    return 0;
}