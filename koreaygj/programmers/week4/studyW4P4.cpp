#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
main()
{
  int i_size = 100;
  char ch_input[i_size] = {0};
  int i_count1 = 0;
  int i_count2 = 0;
  int i_result = 0;
  char ch_result[10] = {0};
  stack<char> stk;
  stack<char> str;
  while (1)
  {
    cin.getline(ch_input, i_size, '\n');
    i_size = strlen(ch_input);
    if (ch_input[0] == '.')
      break;
    for (int i = 0; i < i_size; i++)
    {
      stk.push(ch_input[i]);
    }
    // for (int k = 0; k < i_size; k++)
    // {
    //   cout << ch_input[k];
    // }
    while (!stk.empty())
    {
      switch (stk.top())
      {
      case ')':
        i_count1++;
        stk.pop();
        str.push(')');
        break;
      case '(':
        if (str.top() == ']')
        {
          str.push('(');
          stk.pop();
          break;
        }
        i_count1--;
        str.push('(');
        stk.pop();
        break;
      case ']':
        i_count2++;
        stk.pop();
        str.push(']');
        break;
      case '[':
        if (str.top() == ')')
        {
          stk.pop();
          str.push('[');
          break;
        }
        i_count2--;
        stk.pop();
        str.push('[');
        break;
      default:
        stk.pop();
        break;
      }
      if (i_count1 < 0 || i_count2 < 0)
      {
        stk.pop();
        break;
      }
    }
    if (i_count1 == 0 && i_count2 == 0)
    {
      ch_result[i_result] = '1';
    }
    else
    {
      ch_result[i_result] = '0';
    }
    cout << i_count1 << i_count2 << endl;
    i_count1 = 0;
    i_count2 = 0;
    i_result++;
    i_size = 100;
  }
  for (int j = 0; j < i_result; j++)
  {
    if (ch_result[j] == '1')
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
