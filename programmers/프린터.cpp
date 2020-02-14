/*
2020.02.14
https://programmers.co.kr/learn/courses/30/lessons/42587

그때 그때 우선순위를 찾아내서 최대 우선순위면 answer++ 을 해준다. 
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(vector<int> priorities, int location) {

	int answer = 0;
	int len = priorities.size();

	vector<pair<int, int>> vp;


	// 특성부여
	pair<int, int> p;
	for (int i = 0; i < len; i++) {
		if (i == location) {
			p = make_pair(priorities[i], 1);
		}
		else {
			p = make_pair(priorities[i], 0);
		}
		vp.push_back(p);
	}
  
  
	int i = 0;
	while (true) {
		pair<int, int> cur = vp[i];
		int flag = false;
		for (int j = i + 1; j < vp.size(); j++) {
			if (cur.first < vp[j].first) {
				vp.push_back(cur);
				vp[i].second = -1; //안해도 상관없음. 그냥 계산 끝난 부분인것을 표시하고 싶었다. (디버깅 용)
				flag = true;
				i++;
				break;
			}
		}
		if (!flag) {
			cur.first = -1;  // 안해도 상관없음. 그냥 프린트 했음을 표시하고 싶었다. (디버깅 용)
			i++;
			answer++;
			if (cur.second == 1) {
				break;
			}
		}
	}
	
	return answer;

}
