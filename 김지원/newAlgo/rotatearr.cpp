#include <iostream>
#include <vector>

void rotateLeft90(vector<vector<int>>){
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = key[j][m - i - 1];
        }
    }
}