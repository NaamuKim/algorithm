#include <bits/stdc++.h>

#define pp pair<int,int>

using namespace std;

int n, c, a[1004];
map<int,int> _map, first;

bool cmp(const pp& a, const pp& b) {
	if (a.second == b.second){
        return first[a.first] < first[b.first];
    } 
    return a.second > b.second;
}

int main(){
    cin >> n >>c;
    for(int i =0; i <n; i++){
        cin >>a[i];
        _map[a[i]]++;
        if(first[a[i]] == 0) first[a[i]]=i+1;
    }
    vector<pp> vec( _map.begin(), _map.end() );
	sort(vec.begin(), vec.end(), cmp);
    for(auto num: vec){
        for(int i =0; i < num.second;i++){
            cout << num.first <<" ";
        }
    }
    // 맵 밸류가 큰 것부터 밸류 갯수만큼 키 출력
    return 0;
}