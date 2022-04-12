#include <bits/stdc++.h>

using namespace std;

int dy = {0, 1, 0, -1};
int dx = {1, 0, -1, 0};
int n, m, ret sy, sx, ry, rx;
int a[100][100];
queue<int> q;

int main(){
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ry >> rx;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
}