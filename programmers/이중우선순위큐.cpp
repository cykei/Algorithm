/*
2020.02.28
https://programmers.co.kr/learn/courses/30/lessons/42628

1시간 23분 +2
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	unordered_set<int> erase;
	for (int i = 0; i < operations.size(); i++) {
		string cur = operations[i];
		char order = cur[0];
		int number = atoi(cur.substr(2).c_str());

		if (order == 'I') {
			/*  if( maxHeap.empty() || minHeap.empty()){
				  while(!maxHeap.empty()) maxHeap.pop();
				  while(!minHeap.empty()) minHeap.pop();
			  }*/
			maxHeap.push(number);
			minHeap.push(number);
		}
		else {
			if (number == 1 && !maxHeap.empty()) {
				while (!maxHeap.empty() && erase.find(maxHeap.top()) != erase.end()) {
					maxHeap.pop();
				}
				if (!maxHeap.empty()) {
					erase.insert(maxHeap.top());
					maxHeap.pop();
				}
			}
			else if (number == -1 && !minHeap.empty()) {
				while (!minHeap.empty() && erase.find(minHeap.top()) != erase.end()) {
					minHeap.pop();
				}
				if (!minHeap.empty()) {
					erase.insert(minHeap.top());
					minHeap.pop();
				}
			}
		}
	}



	if (maxHeap.empty() || minHeap.empty() || maxHeap.top() < minHeap.top()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(maxHeap.top());
		answer.push_back(minHeap.top());
	}

	return answer;
}
