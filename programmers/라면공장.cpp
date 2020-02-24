/*
2020.02.24
https://programmers.co.kr/learn/courses/30/lessons/42629

heap 문제 LV2
+6
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int j=0;
    priority_queue<int> q;
    for (int i=0; i<k; i++){
        if(i==dates[j]){
            q.push(supplies[j]);
            j++;
        }
        if(stock==0){
            stock+=q.top();
            answer++;
            q.pop();
        }
        stock--;
    }
    return answer;
}
