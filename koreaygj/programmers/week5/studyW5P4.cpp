#include <iostream>
#include <queue>
using namespace std;
int main()
{
  queue<int> per, ans;
  int in, ik;
  int ncount = 1;
  cin >> in >> ik;
  for (int i = 1; i <= in; i++)
    per.push(i);
  while (per.empty() != 1)
  {
    if ((ncount % ik) == 0)
    {
      ans.push(per.front());
      per.pop();
    }
    else
    {
      per.push(per.front());
      per.pop();
    }
    ncount++;
  }
  cout << "<";
  while (ans.empty() != 1)
  {
    if (ans.size() == 1)
    {
      cout << ans.front() << ">";
      ans.pop();
    }
    else
    {
      cout << ans.front() << ", ";
      ans.pop();
    }
  }
  return 0;
}