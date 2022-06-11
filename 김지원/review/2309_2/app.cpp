#include <bits/stdc++.h>
using namespace std;
int arr[10], sum, flag1, flag2;

int main(){
    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum-(arr[i]+arr[j])==100){
                flag1=arr[i];
                flag2=arr[j];
                break;
            }
        }
    }
    sort(arr, arr+9);
    for(int i=0; i<9; i++){
        if(arr[i]==flag1||arr[i]==flag2) continue;
        else cout <<arr[i]<<"\n";
    }
    return 0;
}