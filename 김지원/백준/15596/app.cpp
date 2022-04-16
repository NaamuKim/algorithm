#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int> &a){
    long long sum = 0;
    for(int item : a) sum+=item;
    return sum;
}

