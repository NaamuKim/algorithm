#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main() {
    for(int i = 1; i < 10; i++) v.push_back(i);

    rotate(v.begin(), v.begin()+1, v.end());
    for(vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
        cout << ' ' << *it;
    cout << "\n";
    return 0;
}