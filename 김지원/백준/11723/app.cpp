#include<bits/stdc++.h>
using namespace std;
int n, m, x;
char s[10];
int main(){
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%s %d", &s, &x);
        if (s[0]=='a' && s[1]=='d') n |= (1 << x);
        else if(s[0]=='r') n &= ~(1<<x);
        else if(s[0]=='c') printf("%d\n", (n&(1 << x)) ==0? 0: 1);
        else if(s[0]=='t') n^=(1<<x);
        else if(s[0]=='e') n = 0;
        else n=(1<<21)-1;
    }
    return 0;
}