#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
문제 : https://programmers.co.kr/learn/courses/30/lessons/17678
*/

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	priority_queue<int, vector<int>, greater<int>> time;
	for (auto i = 0; i < timetable.size(); i++) {
		string s = timetable[i];
		int h1 = s[0] - '0';
		int h2 = s[1] - '0';
		int m1 = s[3] - '0';
		int m2 = s[4] - '0';
		int min = (h1 * 10 + h2) * 60 + m1 * 10 + m2;

		time.push(min); //push는 O(log n).
	}

	int startTime = 540;

	int maxPerson = n * m;
	int ansTime;
	int copy_m = m;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		int shuttleTime = startTime + i * t;
		cnt = 0;
		while (!time.empty() && cnt < m) {
			if (time.top() <= shuttleTime) {
				time.pop(); 
				cnt++; 
			}
			else {
				break;
			}
		}
	}

	cnt = 0;
	startTime = startTime + (n - 1) * t; // 막차 출발 시간

	while (!time.empty() && cnt < m - 1) { //막차니까 m-1일때까지만. 
		if (time.top() <= startTime) {
			time.pop();
			cnt++;
		}
		else {
			break;
		}
	}

	if (time.empty() || time.top() > startTime) {

		ansTime = startTime;

	}
	else {
	
		ansTime = time.top() - 1;
	
	}

	int ansHour = ansTime / 60;
	int ansMin = ansTime % 60;
	if (ansHour != 10 && ansHour / 10 == 0) answer = "0" + to_string(ansHour);
	else answer = to_string(ansHour);
	if (ansMin != 10 && ansMin / 10 == 0) answer += ":0" + to_string(ansMin);
	else answer += ":" + to_string(ansMin);
	return answer;


}
