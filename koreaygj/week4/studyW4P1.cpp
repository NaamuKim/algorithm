#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  int i_size = 100;
  char ch_input[i_size];
  int i_index1, i_index2, i = 0;
  bool flag = false;
  bool flag1 = false;
  cin.getline(ch_input, i_size, '\n');
  i_size = strlen(ch_input);
  cout << i_size;
  // for (int i = 0; i < i_size; i++)
  while (i <= i_size)
  {
    if (ch_input[i] == '(')
    {
      flag = true;
      i_index1 = i;
      cout << "index 1  " << i_index1 << endl;
    }
    if (ch_input[i] == ')' && flag == true)
    {
      flag1 = true;
      i_index2 = i;
      cout << "index 2  " << i_index2 << endl;
    }
    i++;
    if (flag == true && flag1 == true)
    {
      int i_del = i_index2 - i_index1;
      i_del++;
      cout << "i_del  " << i_del << endl;
      for (int k = i_index1; k < i_size; k++)
      {
        ch_input[k] = ch_input[k + i_del];
      }
      i_size -= i_del;
      flag = false;
      flag1 = false;
      for (int j = 0; j < i_size; j++)
      {
        cout << ch_input[j];
      }
      cout << endl;
      i = 0;
    }
  }
  for (int l = 0; l < i_size; l++)
  {
    cout << ch_input[l];
  }
  return 0;
}
