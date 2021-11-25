#include <iostream>
#include <vector>
using namespace std;
string solution(string s, int n)
{
  string answer = "";
  string a;
  vector<string> L = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
  vector<string> S = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  for (int i = 0; i < s.size(); i++)
  {
    a = s[i];
    for (int j = 0; j < L.size(); j++)
    {
      if (a == L[j])
      {
        if (j + n > 25)
          answer += L[j + n - 26];
        else
          answer += L[j + n];
        break;
      }
      if (a == S[j])
      {
        if (j + n > 25)
          answer += L[j + n - 26];
        else
          answer += S[j + n];
        break;
      }
      if (a == " ")
      {
        answer += " ";
        break;
      }
    }
  }
  return answer;
}
int main(void)
{
  string s;
  int n;
  cin >> s >> n;
  solution(s, n);
  return 0;
}