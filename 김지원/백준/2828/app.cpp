#include <bits/stdc++.h>

using namespace std;

int n ,m ,j, k, temp;
int cnt =0;

int main(){
    cin >> n >> m;
    cin >> j;
    int l =1; 
    for(int i =0; i < j; i++){
        int r = l+m-1;
        cin >> temp;
        if(temp>=l && temp<=r) continue;
        else {
            if(temp<l) {
                cnt+=l-temp; 
                l=temp;
            }
            else {
                cnt+=temp-r;
                l+=temp-r;
        }
        }
    }
    cout << cnt << "\n";    
    return 0;
}
    

