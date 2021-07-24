#include <iostream>
using namespace std;

int digit_sum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}


int main()
{
    int n;
    cin >> n;

    int max_num = 0, max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        int sum = digit_sum(num);
        if (max_sum < sum)
        {
            max_num = num;
            max_sum = sum;
        }
        else if (max_sum == sum && max_num < num)
        {
            max_num = num;
        }
    }

    cout << max_num << endl;

    return 0;
}