#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
/*
1939 - 중량제한
풀이 : BFS + 이분탐색
어려웠던 점 :
  bfs() 내에서 queue 선언해야 나중에 재사용 할 수 있는데 main()에서 선언해가지고 꼬였었음.
  비교인자인 ans가 있어야 하는데 처음에 mid로 출력해대서 틀렸습니다 뜸.
시간복잡도 : 
  Log2(10억) = 30 , 간선의 갯수 = 10만 => 10만 * 30 = 300만
  
5432KB 60ms
*/
using namespace std;
int n, m, startN, endN;
vector<pair<int, int>> adj[10001];
int check[10001];

int bfs(int weight) {
	queue<int> q;
	q.push(startN);
	check[startN] = 1;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (front == endN) {
			return 1;
		}
		for (auto next : adj[front]) {
			int node = next.first;
			int w = next.second;
			if (!check[node] && w >=weight) {
			
				q.push(node);
				check[node] = 1;
				
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	scanf("%d %d", &startN, &endN);
	int ans = 0; 
	int left = 1;
	int right = 1000000000;
	int mid;
	
	while (left <= right) {
		memset(check, 0, sizeof(check));
		mid = (left + right) / 2;
		int result = bfs(mid);
		if (result == 0) {
			right = mid - 1;
		}
		else {
			if (ans < mid) ans = mid;
			left = mid + 1;
		}
		
	}

	printf("%d",ans);
}
