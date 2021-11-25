#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] >= 'a' && s[i] <= 'z') {

            s[i] = ('a' + (s[i] + n - 'a') % 26);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {

            s[i] = ('A' + (s[i] + n - 'A') % 26);
        }

        answer += s[i];
    }

    return answer;
}

int main(void) {

    cout << (string)solution("AB", 1) << '\n';
    cout << (string)solution("z", 1) << '\n';
    cout << (string)solution("a B z", 4) << '\n';

    return 0;
}