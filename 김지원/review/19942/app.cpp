#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
int n, mp, mf, ms, mv, b, c, d, e, sum, ret=INF;
struct n{
    int p, f, s, v, cost;
} a[16]; 
//key:cost value: 재료번호 배열의 매열
map<int,vector<vector<int>>> v_ret;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i =0; i<n; i++){
        cin >>a[i].p >> a[i].f >> a[i].s >> a[i].v >>a[i].cost;
    }
    for(int i =1; i<(1<<n); i++){
        b = c = d = e = sum = 0;
        vector<int> v; 
        for(int j=0; j<n; j++){
            //해당 자리에 비트가 켜져있으면
            if(i & (1<<j)){
                v.push_back(j+1);
                b+=a[j].p;
                c+=a[j].f;
                d+=a[j].s;
                e+=a[j].v;
                sum+=a[j].cost;
            }
            if(b>=mp && c>=mf && d>=ms && e>=mv){
                if(ret>=sum){
                    ret=sum;
                    v_ret[ret].push_back(v);
                }
            }
        }
    }
    if(ret==INF) cout << -1 <<"\n";
	else{
        sort(v_ret[ret].begin(), v_ret[ret].end());  
		cout << ret << "\n";
		for(int a : v_ret[ret][0]){
			cout << a << " ";
		} 
	}  
    return 0;
}