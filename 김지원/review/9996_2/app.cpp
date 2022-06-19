#include <bits/stdc++.h>
using namespace std;
int n;
string s, file,pre,suf;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    int id= s.find('*');
    pre= s.substr(0,id);
    suf=s.substr(id+1);
    cout << pre << " " << suf <<"\n";
    for(int i=0; i<n; i++){
        bool flag = true;
        cin >> file;
        for(int i=0; i<pre.size(); i++){
            if(pre[i]!=file[i]){
                flag=false;
            }
        }
        for(int i=0; i<suf.size(); i--){
            if(suf[suf.size()-1]!=file[file.size()-1-i]){
                flag =false;
            }
        }
        if((pre.size()+suf.size())>file.size()) flag=false;
        flag ? cout <<"DA"<<"\n" : cout <<"NE" <<"\n";
    }
    return 0;
}