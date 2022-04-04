#include <iostream>

using namespace std;

const int mxy=3;
const int mxx=4;

int a[mxy][mxx];

int main(){
    for (int i = 0; i < mxy; i++){
        for (int j = 0; j < mxx; j++){
            a[i][j] = (i+j);
        }
    }

// 첫번째 차원 > 두번째 차원 순으로 탐색해야 함
// c++에서 첫번째 차원을 기준으로 캐싱이 되기 때문
    for(int i = 0; i < mxy; i++ ){
        for(int j = 0; j < mxx; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}