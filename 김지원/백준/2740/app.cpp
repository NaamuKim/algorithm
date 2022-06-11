#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int MAX = 100;

int a[MAX][MAX],b[MAX][MAX];

int result[MAX][MAX];

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    cin >> m >> k;
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            cin >> b[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            for(int h=0; h<m; h++){
                result[i][j]+=(a[i][h]*b[h][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout << result[i][j] <<" ";
        }
        cout << "\n";
    }
    return 0;
}

