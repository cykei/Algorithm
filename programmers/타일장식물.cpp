
/*
2020.05.04
https://programmers.co.kr/learn/courses/30/lessons/43104
소요시간 15분 
동적계획법
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;

    long fibo[81];

    fibo[1] =1;
    fibo[2] =1;
    for (int i=3; i<=N; i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }

    if (N==1) answer = 1;
    else if( N==2) answer = 6;
    else if(N==3) answer = 10;
    else{
    answer = fibo[N]*3 + fibo[N-1]*2 + fibo[N-2]*2 + fibo[N-3];

    }

    return answer;
}
