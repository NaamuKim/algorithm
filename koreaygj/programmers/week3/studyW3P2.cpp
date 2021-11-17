#include <iostream>
using namespace std;
int main()
{
  int i_num, i_sum = 0;
  int i_st, i_tot = 0;
  int i_count = 0;
  bool flag = false;
  int i = 0;
  cin >> i_num >> i_sum;
  int i_arr[i_num] = {0};
  for (int i = 0; i < i_num; i++)
  {
    cin >> i_arr[i];
  }
  for (i_st = 0; i_st < i_num; i_st++)
  {
    i = i_st;
    do
    {
      i_tot += i_arr[i];
      if (i_tot == i_sum)
      {
        flag = true;
        ++i_count;
        i_tot = 0;
      }
      if (i_tot > i_sum)
      {
        flag = true;
        i_tot = 0;
      }
      i++;
    } while (flag == 0);
    flag = 0;
  }
  cout << i_count << endl;
}