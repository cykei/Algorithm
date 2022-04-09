/*

2022.04.09
https://programmers.co.kr/learn/courses/30/lessons/42586

한번 순회에 남은시간들 다 구해서 저장한다.
남은 시간배열을 순회해서 answer를 구한다.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> temp;
	for (int i = 0; i < progresses.size(); i++) {
		int time = (100-progresses[i]) / speeds[i];
		if ((100-progresses[i]) % speeds[i] != 0) time++;
		temp.push_back(time);
	}
    int cur = temp[0];
    int cnt = 1;
	for (int i=1; i<temp.size(); i++) {
        if(temp[i] <= cur) cnt++;
        else {
            answer.push_back(cnt);
            cur = temp[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    

	return answer;
}
