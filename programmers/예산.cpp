/*
2020.03.01
https://programmers.co.kr/learn/courses/30/lessons/43237

이분탐색 안쓰고 푸는 방법 (프로그래머스 다른 사람풀이 참조)
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int numbers = budgets.size();

    sort(budgets.begin(),budgets.end());
    for(auto itr=budgets.begin(); itr!= budgets.end(); itr++){
        
         printf("numbers :%d, M: %d\n", numbers,M);
         printf("*itr:%d, M/numbers: %d\n",*itr, M/numbers );
        if(*itr > (M / numbers)) return M/numbers; 
        //제일 작은 예산이 최대 균등분배 금액보다 크면 그게 limit가 된다.
        else{
            // 제일 작은 예산이 최대 균등분배(M/numbers) 금액보다 작았다면
            // 그 금액을 빼고 남는 여유분이 있다는 뜻임으로 이 여유분을 최대 균등분배액에 더해주기 위해
            // 총 예산에서 가장 작은 예산을 빼고, numbers 도 줄여준다.
            M -= *itr;
            numbers--;
            
        }
    }

    return budgets.back();
}
