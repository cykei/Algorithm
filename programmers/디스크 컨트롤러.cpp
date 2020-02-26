/*
https://programmers.co.kr/learn/courses/30/lessons/42627
0초부터 시작하는 작업이 무조건 있을것이라는 가정하에 아래 코드는 +8점을 받으며 돌아감
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time=0;
    int j=0;
    int len = jobs.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    sort(jobs.begin(), jobs.end());
    
    while(j<jobs.size() || !pq.empty()){
        if(j<jobs.size() && time >=jobs[j][0]){ // 현재시간이 작업의 시작시간 이상이면
            pq.push(make_pair(jobs[j][1], jobs[j][0])); // push(종료시간, 시작시간)
            j++;
            continue;
        }
        if(!pq.empty()){
            time+=pq.top().first;  // 종료시간을 더한다.
            answer+=time - pq.top().second;  // answer += (지금시간 - 시작시간) 
            pq.pop();
        }else{
            time=jobs[j][0];
        }
    }
    
    return answer/len;
}
