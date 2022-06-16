#include <bits/stdc++.h>
using namespace std;
int n, m, b, mintime=987654321, board[501][501], maxheight=-1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
   for (int height = 0; height <= 256; height++) {
		int inven = 0;//인벤에서 꺼내는게 필요한거1초 늘어남
		int remove = 0;//제거하는 양 2초 늘어남 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int curheight = board[i][j] - height;
				if (curheight < 0) inven -= curheight;
				else remove += curheight;
			}
		}
		if (remove + b >= inven) {
			int ttime = 2 * remove + inven;
			if (mintime >= ttime) {
				mintime = ttime;
				maxheight = height;
			}
		}
	}
    cout << mintime << " " << maxheight <<'\n';
    return 0;
}
