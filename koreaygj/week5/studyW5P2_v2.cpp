#include <iostream>
using namespace std;
int main()
{
  int i_cmd = 0;
  int i_num = 0;
  int i_case = 0;
  char ch_cmd[10];
  cin >> i_cmd;
  cin.ignore();
  int i_que[i_cmd] = {0};
  for (int i = 0; i < i_cmd; i++)
  {
    cin.get(ch_cmd, 10);
    cin.ignore();
    if (ch_cmd[1] == 'o')
    {
      bool flag;
      for (int k = 0; k < i_cmd; k++)
      {
        if (i_que[k] != 0)
        {
          cout << i_que[k] << endl;
          i_que[k] = 0;
          flag = false;
          break;
        }
        else
          flag = true;
      }
      if (flag == true)
        cout << -1 << endl;
    }
    else if (ch_cmd[1] == 'i')
    {
      int count = 0;
      for (int k = 0; k < i_cmd; k++)
      {
        if (i_que[k] != 0)
          count++;
      }
      cout << count << endl;
    }
    else if (ch_cmd[1] == 'm')
    {
      int count = 0;
      for (int k = 0; k < i_cmd; k++)
      {
        if (i_que[k] != 0)
          count++;
      }
      if (count == 0)
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    else if (ch_cmd[1] == 'r')
    {
      bool flag;
      for (int k = 0; k < i_cmd; k++)
      {
        if (i_que[k] != 0)
        {
          cout << i_que[k] << endl;
          flag = false;
          break;
        }
        else
          flag = true;
      }
      if (flag == true)
        cout << -1 << endl;
    }
    else if (ch_cmd[1] == 'a')
    {
      cout << i_que[i_cmd - 1] << endl;
    }
    else if (ch_cmd[1] == 'u')
    {
      string num;
      num = ch_cmd[5];
      int i_put = stoi(num);
      for (int k = 1; k < i_cmd; k++)
        i_que[k - 1] = i_que[k];
      i_que[i_cmd - 1] = i_put;
    }
  }
  return 0;
}