    #include <bits/stdc++.h>
    using namespace std;
    int n, c, a[1004];
    map<int, int> _map, first;
    typedef pair<int,int> pi;
    bool cmp(pi a, pi b){
        if(a.second==b.second) return first[a.first]<first[b.first];
        else return a.second>b.second;
    }

    int main(){
        cin >> n >> c;
        for(int i=0; i<n; i++){
            cin >> a[i];
            _map[a[i]]++;
            if(first[a[i]]==0) first[a[i]]=i+1;
        }
        vector<pi> v(_map.begin(),_map.end());
        sort(v.begin(), v.end(), cmp);
        for(auto it: v) {
            for(int i=0; i<it.second; i++){
                cout << it.first <<" ";
            }
        }
    }