/*

2020.02.13
https://programmers.co.kr/learn/courses/30/lessons/42588

역순으로 순회하면서 큰 탑이 나오면 저장한다.

*/


#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    int size = heights.size();
    vector<int> answer;
    answer.resize(size,0);
    for (int i=heights.size()-1; i>0; i--){ // i=sender
        for (int j=i-1; j>=0; j--){ // j=receiver
            if(heights[i] < heights[j]){
                answer[i]=j+1;
                break;
            }
        }
    }
    return answer;
}
