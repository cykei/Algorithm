#include <string>
#include <vector>
/*
2020.02.18

https://programmers.co.kr/learn/courses/30/lessons/42585

스택문제인데 또 스택안썼네 에휴
10:43~11:15  33분소요
*/
using namespace std;
int solution(string arrangement) {
    int answer = 0;
    int i=0;
    int tomak=0; 
    while(true){
        if (arrangement.at(i)=='('&& arrangement.at(i+1)==')'){
            //레이저 발견 -> 잘라버령!
            answer+=tomak;
            i+=2;
        } 
        else if(arrangement.at(i)=='(') {
            tomak++;
            i++;
        }
        else if(arrangement.at(i)==')'){
            answer++; //꼬다리 추가
            tomak--;
            i++;
        }
        //printf("i: %d, tomak: %d, answer: %d\n",i-1,tomak,answer);
        if(i==arrangement.length()) break;
    }
    return answer;
}
