/*
2020.03.01
https://programmers.co.kr/learn/courses/30/lessons/43237
2시간  +6

이분탐색 (그러나 이분탐색 안써도 풀 수 있다)
*/


#include <string>
#include <vector>
#include<algorithm>
#include<stack>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    int left = budgets.size();
    int right = budgets[left-1];
    int mid;
    long long yesan;
    stack<pair<long long,int>> s;
    while(left<=right){
        mid = (left + right)/2;
        printf("left: %d, right: %d, mid : %d\n",left, right,mid);
        yesan=0;
        for (int i=0; i<budgets.size(); i++){
            if(budgets[i]<=mid){
                yesan+=budgets[i];
            }else{
                yesan+= (budgets.size()-i)*mid;
                break;
            }
        }
        printf("yesan: %d\n",yesan);
        s.push(make_pair(yesan,mid));
        if(yesan==M){
            return mid;
        }else if(yesan<M){
            left=mid+1;
        }else{
            right=mid-1;
        }
        
    }
    while(yesan>M){
        s.pop();
        yesan=s.top().first;
    }
    mid=s.top().second;
    
    return mid;
}
