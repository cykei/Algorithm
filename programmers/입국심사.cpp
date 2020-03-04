/*
2020.03.03
https://programmers.co.kr/learn/courses/30/lessons/43238

이분탐색 + long long

1일 +6
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long right = (long long)times.back()*n;
    long long left = (long long)times[0];
    long long mid;
    long long answer = right;
    
    while( left <= right){
        mid = (left+right)/2;
        long long temp=0;  // 얘는 long long 아니어도 될줄 알았다...ㅎ
        
        for (int i=0; i<times.size(); i++){
            temp += mid/times[i];
        }
        if(temp < n){
            left = mid+1;
        }else {
            if( mid < answer) answer = mid;
            right = mid-1;
        }
    }
    
    return answer;
}
