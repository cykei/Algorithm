/*
2021.03.01 오전 12:47분 (새벽) ~ 오전 11시 5분
놀다가 코든 짠 시간은 정작 15분 정도인가...? ㅎㅎㅎㅎ
심지어 처음짠게 맞았어. ㅋㅋㅋㅋ

문제

n개의 동영상이 존재 (1<=n<=5000)
새동영상은 기존 영상과의 연관도("USADO") 로 삽입.
n-1 개의 동영상 쌍을 골라서 USADO 를 계산. 각동영상은 정점. 이 그래프는 단절이 없는 그래프. 
임의의 동영상에 대해서 k 이상의 USADO를 가진 동영상의 개수를 구해라. 

입력

n,q        ( 1<= n, q <= 5000) (n = 정점의 개수, q = 질문의 개수)
pi, qi, ri (pi, qi  의 usado 는 ri) (1<=pi,qi<=n, 1<=ri <= 10억)
ki, vi     (동영상 vi에 대해 USADO가 ki 이상인 동영상 개수는?)

가중치 있는 간선그래프. 풀이는... BFS?

*/


#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstring>
#define scanf scanf_s

using namespace std;

int n, q;

vector<pair<int, int>> graph[5001];
int visited[50001];

void bfs(int k, int v) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	int answer = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			pair<int, int> next = graph[cur][i];
			if (!visited[next.first] && next.second >= k) {
				q.push(next.first);
				visited[next.first] = 1;
				answer++;
			}
		}
	}
	printf("%d\n", answer);
}

int main() {
	
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n-1; i++) {
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		graph[p].push_back(make_pair(q, r));
		graph[q].push_back(make_pair(p, r));
	}
	
	for (int i = 0; i < q; i++) {
		int k, v;
		scanf("%d %d", &k, &v);
		bfs(k, v);
	}

	return 0;
}
