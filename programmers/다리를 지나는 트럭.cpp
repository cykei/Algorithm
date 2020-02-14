/*

2020.02.13

https://programmers.co.kr/learn/courses/30/lessons/42583

1초가 지날때마다 다리에 올라가있는 모든 트럭의 시간을 1씩 줄인다.
*/


int solution(int bridge_length, int weight, vector<int> truck_weights) {

	int answer = 1;
	vector<int> v; // 트럭 시간
       queue<int> q;  // 다리에 올라가 있는 트럭들
	int sum = truck_weights[0];  // 다리에 올라가 있는 트럭들의 무게 합

       int i = 1;     // 현재 트럭 인덱스
	v.push_back(bridge_length-1); //넣으면서 일초가 흘렀다.
	q.push(truck_weights[0]);
	while (!q.empty() || i < truck_weights.size()) {
		if (i<truck_weights.size() && sum + truck_weights[i] <= weight) {
			// 다리에 올라탄다.
			v.push_back(bridge_length);
			q.push(truck_weights[i]);
			sum += truck_weights[i];
			i++;
		}
		
		//시간을 경과한다.
		answer++;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != 0 && v[i]!=-1) {
				v[i]--;
			}
			if( v[i]== 0){
				//시간이 전부 경과됐는가?
				v[i] = -1;
				sum -= q.front();
				q.pop();
			}
		}
	}
	return answer+1;
}
