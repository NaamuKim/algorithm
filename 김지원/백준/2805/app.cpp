#include <bits/stdc++.h>
using namespace std;
int M, ret, a;
long long sum, n, m;
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
        if(a>=M){
            M=a;
        }
    }
    int left =0;
    int right=M;
    while(left<=right){
        int mid =(left+right)/2;
        sum = 0;
        for(int i=0; i<n; i++){
            if(mid<vec[i]) sum+=vec[i]-mid;
        }
        if(sum>=m){
            if(ret<mid) ret=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    } 
    cout << ret <<"\n";
    return 0;
}