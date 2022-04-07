#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool cmp(int a, int b){
    return a < b;
}

int main(){
    for(int i =1; i<=10; i++) v.push_back(i);
    sort(v.begin(), v.end(), cmp);
    for (int it : v) cout << it << " ";
}