#include <iostream>
#include <string>
using namespace std;
int que_push(int que[], char cmd[], int size);
int que_pop(int que[], int size);
int que_size(int que[], int size);
int que_empty(int que[], int size);
int que_front(int que[], int size);
int que_back(int que[], int size);
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
    //cout << ch_cmd[5] << endl;
    cin.ignore();
    if (ch_cmd[1] == 'o')
      i_case = 1;
    else if (ch_cmd[1] == 'i')
      i_case = 2;
    else if (ch_cmd[1] == 'm')
      i_case = 3;
    else if (ch_cmd[1] == 'r')
      i_case = 4;
    else if (ch_cmd[1] == 'a')
      i_case = 5;
    else if (ch_cmd[1] == 'u')
      i_case = 0;
    //cout << i_case << endl;
    switch (i_case)
    {
    case 0:
      que_push(i_que, ch_cmd, i_cmd);
      break;
    case 1:
      que_pop(i_que, i_cmd);
      break;
    case 2:
      que_size(i_que, i_cmd);
      break;
    case 3:
      que_empty(i_que, i_cmd);
      break;
    case 4:
      que_front(i_que, i_cmd);
      break;
    case 5:
      que_back(i_que, i_cmd);
      break;
    default:
      break;
    }
  }
  return 0;
}
int que_push(int que[], char cmd[], int size)
{
  string num;
  num = cmd[5];
  int i = stoi(num);
  for (int k = 1; k < size; k++)
  {
    que[k - 1] = que[k];
  }
  que[size - 1] = i;
  // for (int j = 0; j < size; j++)
  // {
  //   cout << que[j];
  // }
  // cout << endl;
  return 0;
}
int que_pop(int que[], int size)
{
  bool flag;
  for (int i = 0; i < size; i++)
  {
    if (que[i] != 0)
    {
      cout << que[i] << endl;
      que[i] = 0;
      flag = false;
      break;
    }
    else
      flag = true;
  }
  if (flag == true)
    cout << -1 << endl;
  // for (int j = 0; j < size; j++)
  // {
  //   cout << que[j];
  // }
  // cout << endl;
  return 0;
}
int que_size(int que[], int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (que[i] != 0)
      count++;
  }
  cout << count << endl;
  return 0;
}
int que_empty(int que[], int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    if (que[i] != 0)
      count++;
  }
  if (count == 0)
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
int que_front(int que[], int size)
{
  bool flag;
  for (int i = 0; i < size; i++)
  {
    if (que[i] != 0)
    {
      cout << que[i] << endl;
      flag = false;
      break;
    }
    else
      flag = true;
  }
  if (flag == true)
    cout << -1;
  // for (int j = 0; j < size; j++)
  // {
  //   cout << que[j];
  // }
  // cout << endl;
  return 0;
}
int que_back(int que[], int size)
{
  cout << que[size - 1] << endl;
  // for (int j = 0; j < size; j++)
  // {
  //   cout << que[j];
  // }
  // cout << endl;
  return 0;
}