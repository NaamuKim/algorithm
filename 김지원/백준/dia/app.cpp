#include <bits/stdc++.h>
using namespace std;
map<int, int> MAP;
int solution(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        if(MAP.find(arr[i])!=MAP.end()){
            MAP.insert({arr[i],1})
        }
        else {
            MAP[arr[i]]++;
        }
    }
    if(!MAP.size()) cout -1;
    else {
        for(auto child : MAP){
            cout << child.second();
        }
    }
}