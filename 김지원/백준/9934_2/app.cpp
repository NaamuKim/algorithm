#include <bits/stdc++.h>

using namespace std;
vector<int> ret[14];
int n, a[1030];

void go(int s, int e, int level){ 
    if(s > e) return; 
    if(s == e){ 
        ret[level].push_back(a[s]);
        return;
    }
    int mid = (s + e) / 2; // 숫자로써 가운데
    ret[level].push_back(a[mid]); //가운데를 꺼내서 level에 넣는다.
    go(s, mid - 1, level + 1); //왼쪽에서 가운데를 찾자
    go(mid + 1, e, level + 1); //오른쪽에서 가운데를 찾자
    return;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    int _end = (int)pow(2, n) - 1;  //입력 개수
    int num;
    int idx=0;
    while (cin >> num) {
		a[idx++] = num;
	}
    go(0, _end, 1);
    for(int i = 1; i <= n; i++){
        for(int j : ret[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}

