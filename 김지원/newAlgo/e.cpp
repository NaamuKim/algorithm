#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> v[10];
    vector<int> v(5,0);

    cout << v << "\n";
    return 0;
    // vector<vector<int>> checked;
    // vector<vector<int>> v(n + 1, vector<int> (n + 1, 0));
    // fill(v.begin(), v.end(),0);

    // cout << v << " ";
    // return 0;
}
