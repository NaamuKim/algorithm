#include <iostream>
using namespace std;
int main()
{
  int i_n = 0;
  int i_m = 0;
  int i_size[100] = {0};
  int i_max = 0;
  int i_sum = 0;
  cin >> i_n >> i_m;
  cin.ignore();
  for (int i = 0; i < i_n; i++)
  {
    cin >> i_size[i];
  }

  for (int i = 0; i < i_n - 2; i++)
  {
    for (int j = i + 1; j < i_n - 1; j++)
    {
      for (int k = j + 1; k < i_n; k++)
      {
        i_sum = i_size[i] + i_size[j] + i_size[k];
        if (i_sum > i_max && i_sum <= i_m)
          i_max = i_sum;
      }
    }
  }
  cout << i_max << endl;
}
