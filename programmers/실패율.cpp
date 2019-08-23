#include <string>
#include <vector>
#include <algorithm>
/*
* 문제 : https://www.welcomekakao.com/learn/courses/30/lessons/42889
* 어려웠던 점 :
* - 문제이해 잘 못해서 해맴
* - 해당 스테이지까지 도전한 사람을 구하는 for문 매우 신박하다고 생각함. (ㅠㅠ)
* - cmp의 or 다음을 잘못짜서 혼남.
* - barr이 1부터 N까지 값이 들어가있기 때문에 sort의 시작은 +1 부터 +N+1 까지 되야하는데 처음에 무의식적으로 +0 에서 +N으로 썻다가 틀림. 
* - 구현문제.
*/
using namespace std;

struct block{ 
    double fail; // 실패율
    int tip;  // 스테이지 번호
};

bool cmp(const block &a, const block &b){
    return (a.fail > b.fail) || (a.fail==b.fail && a.tip <b.tip);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int check[501]={0};   // check[1] = 1번 스테이지에 도전한 사람 수
    int pnum = stages.size();
    block barr[200001];
    for (auto i=0; i<stages.size(); i++){
        for (int j=1; j<=stages[i]; j++){
            check[j]++;
        }
        barr[stages[i]].fail++;  // barr[1].fail = 1번 스테이지를 도전 중인 사람 수
    }
    
    for (int i=1; i<=N; i++){
        barr[i].tip = i;
        if(!check[i]){
            // 도전한 사람이 없으면
            barr[i].fail = 0;
        }else{
            barr[i].fail = barr[i].fail / check[i];  //barr[1].fail = 1번 스테이지의 실패율
        }
    }
    
    sort(barr+1,barr+N+1, cmp);
    
    for (int i=1; i<=N; i++){
        answer.push_back(barr[i].tip);
    }
    return answer;
}
