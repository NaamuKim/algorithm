#include <iostream>
using namespace std;


int main()
{
    int n, m;   // n: 수열의 원소 개수, m: 연속부분수열의 합
    cin >> n >> m;

    int sequence[100000] = { 0 }; 
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            if (sum == m)   // 연속으로 더했을 때 m과 값이 같으면 cnt++
            {
                cnt++;
                break;
            }

            if (sum > m) break; // m보다 크면 break

            sum += sequence[j];
        }
    }

    cout << cnt;

    return 0;
}

