/*
https://programmers.co.kr/learn/courses/30/lessons/42884

그리디문제 (왜지?)

오름차순으로 정렬해서 겹친부분이 몇개나 있는지 알아내면 되는 문제
(i,0) (i,1) (i+1,0) (i+1,1) 4가지를 비교해가면서 겹친부분이 없어지는 순간에 감시카메라를 설치해주면 된다.

오름차순이기때문에 (i,0) < (i+1, 0) 이라서 이놈은 신경쓸 필요없음
(i,1) < (i+1, 0) : 안겹침, 즉 겹치는 게 끝낫음으로 감시카메라를 설치하고, 겹치는 시작점과 끝점을 재설정한다.
(i,1) >= (i+1, 0) : 무조건 조금은 겹침
                (i,1) <= (i+1, 1) : 끝점이 (i,1) 로 유지된다.
                (i,1) > (i+1, 1) : 끝점이 (i+1, 1) 로 바뀐다. 

소요시간 26분 +4 
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    for (int i=0; i<routes.size() ;i++){
        printf("%d %d\n",routes[i][0],routes[i][1]);
    }
    int start=routes[0][0];
    int end = routes[0][1];
    printf("start: %d, end: %d\n",start, end);
    for (int i=1; i<routes.size(); i++){
        if( end < routes[i][0]) {
            answer++;
            start = routes[i][0];
            end = routes[i][1];
              //printf("start: %d, end: %d\n",start, end); 
        }else{
            start = routes[i][0];
            if(routes[i][1] < end){
                end = routes[i][1];
            }
               //printf("start: %d, end: %d\n",start, end);
        }
    }
    return answer;
}
