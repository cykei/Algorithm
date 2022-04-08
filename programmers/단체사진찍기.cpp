// 완탐문제
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int N;
int visited[8];
int chosen[8];
vector<string> m_data;
map<char, int> mp;
int answer;
void make(int cur) {
    if(cur == 8) {
        // check data

        for (int i=0; i<m_data.size(); i++){
            string command = m_data[i];
            int first = chosen[mp[command[0]]];
            int second = chosen[mp[command[2]]];
            int distance = command[4]-'0';
            char symbol = command[3];
            if(symbol=='='){
                if(abs(first-second)!=distance+1) return;
            }else if(symbol == '>'){
                if(abs(first-second) <= distance+1) return;
            }else if(symbol == '<') {
                if(abs(first-second) >= distance+1) return;
            }
        }
        answer++;
        return;
    }
    for (int i=0; i<8; i++) {
        if(visited[i]==0) {
            visited[i]=1;
            chosen[cur]=i;
            make(cur+1);
            visited[i]=0;
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer=0;
    N=n;
    m_data=data;
    mp.insert({'A',0});
    mp.insert({'C',1});
    mp.insert({'F',2});
    mp.insert({'J',3});
    mp.insert({'M',4});
    mp.insert({'N',5});
    mp.insert({'R',6});
    mp.insert({'T',7});
    
    make(0);
    return answer;
}
