/*

2020.02.14
https://programmers.co.kr/learn/courses/30/lessons/42586

한번 순회에 남은시간들 다 구해서 저장한다.
남은 시간배열을 순회해서 answer를 구한다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len = progresses.size();

    vector<int> remain;
    remain.resize(len);

    int namugi, mok, time;
    // 각 작업이 끝나는 날짜를 계산한다.
    for (int i=0; i<len; i++){
        namugi = (100-progresses[i])% speeds[i];
        mok = (100-progresses[i])/ speeds[i];
        time = namugi>0? mok+1 : mok;

        remain[i] = time;
    }

    int prev=remain[0];
    int cur;
    int result=1;
    for (int i=1; i<len; i++){
        cur = remain[i];
        if (cur <= prev){
            result++;
        }else{
            answer.push_back(result);
            prev = cur; //기준을 변경한다.
            result = 1;
        }    
    }

    answer.push_back(result); //마지막을 넣는다. 


    return answer;
}
