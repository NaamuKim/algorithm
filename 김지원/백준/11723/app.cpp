#include <bits/stdc++.h>

using namespace std;
bool flag;
int n,x; 
string s;
vector<int> v;
int main(){
    cin >> n; 
    for(int i =0; i<n; i++){
        cin >> s >> x;
        switch(string s){
            case "add":
            v.push_back(x);
            break;
            case "remove":
            for(int i =0; i<v.size(); i++){
                if(v[i]==x) v.erase(v.begin()+i,v.begin()+i+1);
            }
            break;
            case "check":
            flag =0;
            for(int i =0; i<v.size(); i++){
                if(v[i]==x) flag =1;
            }
            flag==1 ? cout << 1 <<"\n" : cout << 0 <<"\n";
            break;
            case "toggle": 
            flag =0;
            for(int i =0; i<v.size(); i++){
                if(v[i]==x) {
                    v.erase(v.begin()+i,v.begin()+i+1);
                    flag =1;
                }
            }
            if(flag==0) v.push_back(x);
            break;
            case "all":
            while(v.size()){
                v.pop_back();
            }
            for(int i =1; i<=20; i++){
                v.push_back(i);
            }
            break;
            case "empty":
            while(v.size()){
                v.pop_back();
            }
            break;
            default:
            break;
        }
    }
    return 0;
}