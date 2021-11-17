#include <iostream>
#include <vector>
using namespace std;
int n, k;
int answer = 0;
vector<int> kit;
vector<int> index;
void solution(int count, int sum)
{
  int reset = sum;
  if (count == n)
  {
    answer++;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (index[i] == 1)
      continue;
    index[i] = 1;
    sum += kit[i];
    if (sum >= 500)
      solution(count + 1, sum);
    index[i] = 0;
    sum = reset;
  }
}
int main(void)
{
  cin >> n >> k;
  vector<int> input(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
    input[i] -= k;
    index.push_back(0);
  }
  kit = input;
  solution(0, 500);
  cout << answer << "\n";
  return 0;
}