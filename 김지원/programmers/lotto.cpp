#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min=0;
    int zero=0;
    for(int i=0; i<lottos.size(); i++){
        if(lottos[i]==0){
            zero++;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++){
            if(lottos[i]!=0&&lottos[i]==win_nums[j]) {
                min++;
                break;
            }
        }
    }
    if(min+zero==0) answer.push_back(6);
    else answer.push_back(7-(min+zero));
    if(min==0) answer.push_back(6);
    else answer.push_back(7-min);

    return answer;
}