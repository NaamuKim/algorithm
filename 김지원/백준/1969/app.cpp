#include <bits/stdc++.h>

using namespace std;
string s[1000];
string answer;
char ch;
int n, m, sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i =0; i<n; i++){
        cin >> s[i];
    }
    for(int i =0; i<m; i++){
        map<char,int> _map;
        for(int j =0; j<n; j++){
            _map[s[j][i]]++;
        }
        char ch;
        int max =0;
        for(auto el: _map){
            if(el.second>max){
                max=el.second;
                ch=el.first;
            }
        }
        answer+=ch;
        sum+=n-max;
    }
    cout << answer << "\n" << sum;
    return 0;
}