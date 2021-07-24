#include <iostream>
using namespace std;


int main(void)
{
    string result = "";

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        
        result += ch;
    }

    int idx = 0;
    int score = 0;
    while (1)
    {
        int cnt = 0;
        while (result[idx] == '1')
        {
            cnt++;
            score += cnt;
            idx++;
        }

        idx = result.find('1', idx);

        if (idx == -1)
            break;
    }

    cout << score << '\n';

    return 0;
}