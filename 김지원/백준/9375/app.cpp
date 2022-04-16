#include <bits/stdc++.h>

using namespace std;

int t, n;
string item, cate;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        map<string, int> _map;
        for(int i = 0; i<n; i++){
            cin >> item >> cate;
            _map[cate]++;
        }
        long long ret = 1;
        for(auto c: _map){
            ret *=((long long)c.second+1);
        }5
        ret-=1;
        cout <<ret<< "\n";
    }
    return 0;
}