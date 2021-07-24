#include <iostream>
using namespace std;

int map[52][52] = { 0 };

int dict[4][2] = {
    0, -1,
    -1, 0,
    1, 0,
    0, 1
};


bool isPeak(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dict[i][0];
        int nx = x + dict[i][1];

        if (map[y][x] < map[ny][nx])
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (isPeak(i, j))
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}