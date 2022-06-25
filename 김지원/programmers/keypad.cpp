#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

vector<pair<int,int>> v={
    {3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2},
};
int lpos=10;
int rpos=11;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int it: numbers){
        if(it==1||it==4||it==7){
            answer+='L';
            lpos=it;
        } else if(it==3||it==6||it==9){
            answer+='R';
            rpos=it;
        }else{
            int ldist=abs(v[it].first-v[lpos].first)+abs(v[it].second-v[lpos].second);
            int rdist=abs(v[it].first-v[rpos].first)+abs(v[it].second-v[rpos].second); 
            if(ldist<rdist){
                answer+='L';
                lpos=it;
            } else if(rdist<ldist){
                answer+='R';
                rpos=it;
            } else{
                if(hand=="left"){
                    answer+='L';
                    lpos=it;
                } else{
                    answer+='R';
                    rpos=it;
                }
            }
        }
    }
    return answer;
}