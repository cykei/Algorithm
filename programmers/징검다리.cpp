/*
2020.03.04
https://programmers.co.kr/learn/courses/30/lessons/43236

이분탐색
+8

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {

    /* 
     * 거리의 최솟값을 정하고, 바위들 사이의 거리가 최솟값 이하인 경우 없앤다.(sum++) 
     * 없앤 갯수가 n보다 크다? 최솟값을 줄인다.
     * 없앤 갯수가 n보다 작다? 최솟값을 늘린다.
     * 없앤 갯수가 n보다 작은 경우는 사실 문제 없다. 몇개를 더 지우든 최솟값은 변하지 않을테니까.
     */
     
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int left = 1; 
    int right = distance;
    int mid;
    int sum;
    int len = rocks.size();

    while (left<=right){
        mid = (left + right)/2;
        sum = 0;

        int last = 0;
        for (int i=0;i <rocks.size(); i++){
            if (rocks[i]-last < mid) sum++;
            else {
                last = rocks[i];
            }
        }

        if(sum > n){
            right = mid-1;
        }else{
            left = mid+1;
            answer = mid;
        }
    }

    return answer;
}
