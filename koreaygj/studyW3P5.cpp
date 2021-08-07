#include <iostream>
using namespace std;
#define Max 10000
class failmath
{
  int i_ans[Max] = {0};

public:
  int i_score = 0;
  void numinput(int st_ans[], int num, int student_n);
  void scoreing(int i_check[], int num);
};
void failmath::numinput(int st_ans[], int num, int student_n)
{
  int i_n = 0;

  for (int i = 0; i < num; i++)
  {
    i_ans[i] = st_ans[i_n];
    switch (student_n)
    {
    case 0:
      if (i_n == 4)
        i_n = 0;
      break;
    case 1:
      if (i_n == 7)
        i_n = 0;
      break;
    case 2:
      if (i_n == 9)
        i_n = 0;
      break;
    }
    i_n++;
  }
}
void failmath::scoreing(int i_check[], int num)
{
  for (int i = 0; i < num; i++)
  {
    if (i_ans[i] == i_check[i])
    {
      i_score++;
    }
  }
}
int main()
{
  failmath fail[3];
  int i_num1[] = {1, 2, 3, 4, 5};
  int i_num2[] = {2, 1, 2, 3, 2, 4, 2, 5};
  int i_num3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
  int i_pronum = 0;
  cout << "Problem last number: ";
  cin >> i_pronum;
  cin.ignore();
  int i_check[i_pronum] = {0};
  int i_best[3] = {0};
  int i_score1, i_score2, i_score3 = 0;
  cout << "Problem answer: ";
  for (int i = 0; i < i_pronum; i++)
  {
    cin >> i_check[i];
  }
  for (int i = 0; i < 3; i++)
  {
    switch (i)
    {
    case 0:
      fail[i].numinput(i_num1, i_pronum, i);
      fail[i].scoreing(i_check, i_pronum);
      i_score1 = fail[i].i_score;
      break;
    case 1:
      fail[i].numinput(i_num2, i_pronum, i);
      fail[i].scoreing(i_check, i_pronum);
      i_score2 = fail[i].i_score;
      break;
    case 2:
      fail[i].numinput(i_num3, i_pronum, i);
      fail[i].scoreing(i_check, i_pronum);
      i_score3 = fail[i].i_score;
      break;
    }
  }
  int i_best_num = 0;
  int i_best_score = 0;
  if (i_score3 >= i_score1 && i_score3 >= i_score2)
    i_best_score = i_score3;
  if (i_score2 >= i_score3 && i_score2 >= i_score1)
    i_best_score = i_score2;
  if (i_score1 >= i_score2 && i_score1 >= i_score3)
    i_best_score = i_score1;
  if (i_best_score == i_score3)
  {
    i_best_num++;
    i_best[0] = 3;
  }
  if (i_best_score == i_score2)
  {
    i_best_num++;
    i_best[0] = 2;
    if (i_best_score == i_score3)
      i_best[1] = 3;
  }
  if (i_best_score == i_score1)
  {
    i_best_num++;
    i_best[0] = 1;
    if (i_best_score == i_score2)
    {
      i_best[1] = 2;
      if (i_best_score == i_score3)
        i_best[2] = 3;
    }
    else if (i_best_score == i_score3)
      i_best[1] = 3;
  }
  for (int i = 0; i < i_best_num; i++)
  {
    cout << "가장 많은 문제를 맞힌 사람은 수포자" << i_best[i] << "입니다" << endl;
  }
}