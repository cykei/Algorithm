/*
2021.02.08 9:05~11:11
문제 : https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp#

사각형의 총면적에서 대각선이 지나가는 면적의 합을 빼주면 되는 문제.
아... 대각선이 지나가는 면적은 (w + h -1) 인걸 까먹고 있었다 ㅠㅠ 풀이 보고 "맞다!! 그랬었지!!" 하고 떠올림.
그것만 알면 쉽게 풀리는 문제.
 
 + 프로그래머스에서 계속 실패가 떴었는데  w*h 앞에 (long long) 으로 타입캐스팅 해줘야함.
 
*/

#include <cstdlib>
#include <cstdio>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    if (w==h) answer = (long long)w*h - w;
    else if (abs(w-h)==1){
        answer = (long long)w*h - (w+h-1);
    }
    else{
        // 최대공약수를 구합니다.
        int big = (w>h)?w:h;
        int small= (w<h)?w:h;
        int temp;
        
        while(small!=0){
            temp = big%small;
            big=small;
            small=temp;
        }
        int& gcd = big;
        
        long long totalSize = (long long)w*h;
        
        // 작은 반복구간의 대각선 공간을 구합니다.
        w= w/gcd;
        h= h/gcd;
        
        // 대각선 공간의 총합을 총 면적에서 빼줍니다.
        answer = totalSize- ((w+h-1)*gcd); 
        
    }
    return answer;
}
