#include <bits/stdc++.h>

using namespace std;

int n; 
vector<string> ret;
char a[10];
int vis[10];

bool good(char x, char y, char op){ 
	if(x < y && op == '<') return true;  //앞보다 뒤가 클 때 <면 true
	if(x > y && op == '>') return true;  //뒤보다 앞이 클 떄 >면 true
	return false; 
}
    
void go(int idx, string num){
    if(idx==n+1) { // 기호 개수보다 문자열이 1만큼 길다.(기저) 
        ret.push_back(num);
        return;
    }
    for(int i =1; i<=9; i++){ //숫자 1부터 9까지 가능
        if(vis[i]) continue; // 이미 들어가 있으면 continue
        if(idx==0 || good(num[idx-1],i+'0',a[idx-1])){ // 맨앞이면 그냥 뭐든 된다. // 맨앞아니면 good
            vis[idx]=1;
            go(idx+1, num+to_string(i));
            vis[idx]=0;
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i =0; i<n; i++) cin >> a[i];
    go(0,""); //첫번쨰 인자가 문자열 num에 삽입할 곳의 index, 두번쨰 인자가 첫번째 인자의 index가 있는 문자열
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}