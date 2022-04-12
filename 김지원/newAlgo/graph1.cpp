#include <bits/stdc++.h>

using namespace std;

vector<int> arr[1004];
int dy={-1, 0, 1, 0};
int dx={0, 1, 0, -1};
    
int main(){
    int y = 1;
    int x = 1;
    for(int i = 0; i <= 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << arr[dy][dx]<<"\n";
    }
}