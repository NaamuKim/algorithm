#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int> &a){
    int sum = 0;
    for(int item : a) sum+=item;
    return sum;
}

int main(){
    vector<int> a;
    a[0]=1;
    a[1]=2;
    a[2]=3;
    cout << sum(a) << "\n";
    return 0;
}