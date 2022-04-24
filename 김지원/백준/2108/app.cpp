#include <bits/stdc++.h>

using namespace std;

int a[500001], n, mid, many[500001], r;
float avg;
vector<int> v;
int mx =-4001;

int main(){
    cin >>n;
    for(int i =0; i<n; i++){
        cin >>a[i];
        v.push_back(a[i]);
    }
    int sum=0;
    for(int i =0; i<n; i++){
        sum+=a[i];
        mx=max(mx,a[i]);
        many[i]++;
    }
    avg=sum/v.size();
    sort(v.begin(), v.end());
    mid=v[v.size()/2-1];
    r=v[v.size()-1]-v[0];
    printf("%2lf\n", avg);
    printf("%d",mid);
    printf("")
}