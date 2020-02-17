/*
2020.02.17
https://programmers.co.kr/learn/courses/30/lessons/42842

완전탐색 문제
풀이시간 13분

0.01ms (+3)
*/


#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    if(red == 1) {
        answer.push_back(3);
        answer.push_back(3);
    }
    for (int i=1; i+i <=red; i++){
        if(red%i==0){ 
            //int redrow = i; 
            int redcol = red/i; 
            int temp =(redcol+2)*2 + i*2;
            if(temp== brown){
                answer.push_back(redcol+2);
                answer.push_back(i+2);
                break;
            }
        }
    }
    return answer;
}
