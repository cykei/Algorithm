/*
2020.05.07
https://programmers.co.kr/learn/courses/30/lessons/42841

완전탐색
*/

#include <string>
#include <vector>


// 123 ~ 987까지 다해보면서 baseball의 조건과 맞는 것을 찾는다.
// baseball이 100이하니까, 100*100 * 900 = 9000000 의 시간이 걸린다.
// 10억 이하니까 충분히 가능!
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for (int i=123; i<=987; i++){
        string temp = to_string(i);

        // 이거 두줄 안써서 고생했다. 
        if(temp[0]==temp[1] || temp[0]==temp[2] || temp[1] == temp[2]) continue;
        if(temp[0]=='0'|| temp[1]=='0' || temp[2]=='0') continue;


        int cnt =0;
        for (int j=0; j<baseball.size(); j++){
            string query = to_string(baseball[j][0]);
            int strike,ball;
            strike=ball=0;
            for (int a=0; a<3; a++){
                for (int b= 0; b<3; b++){
                    if( a==b && temp[a]==query[b]){
                          strike++;   
                    }else if(temp[a]==query[b]){
                        ball++;
                    }
                }
            }

           if(strike == baseball[j][1] && ball == baseball[j][2]){
               cnt++;
           }
        }

        if( cnt == baseball.size()) answer++;
    }
    return answer;
}
