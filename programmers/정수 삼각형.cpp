/*
2020.05.04
https://programmers.co.kr/learn/courses/30/lessons/43105
2시 51분 ~ 3시 12분 : 21분

동적계획법
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int count[501][501];
    count[0][0] = triangle[0][0];
    for (int i=1; i<triangle.size(); i++){
        for (int j=0; j<triangle[i].size(); j++){
            count[i][j] = max(count[i-1][j],count[i-1][j-1]) + triangle[i][j];
        }
        
    }
    // 0
    // 0 ,1 
    // 0, 1, 2
    int size = triangle.size();
    
    for (int i=0; i<size; i++){
        if(answer < count[size-1][i]) answer = count[size-1][i]; 
    }
    return answer;
}
