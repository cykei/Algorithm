/*
2019. 10. 17
7576번 토마토 -bfs 문제

풀이 :
1. 숫자1인 애들은 익어있는 애들이니까 큐에 넣고 시작한다.
2. 전방위 탐색하면서 숫자 0 (안익은 애들)인 애들을 큐에넣는다. 단, 0->cur+1 로 바꿔서 map에 기입한다. (cur+1일일째에 토마토가 익었다는 표시)
3. 큐가 빌때까지 탐색을 계속한다.
4. 탐색이 끝났는데 map에 0이 있다면 그 토마토는 익힐수 없는 토마토임으로 -1을 출력한다
5. map에서 가장 큰 숫자를 찾아서 answer에 넣는다. 가장 큰 숫자 = 제일 늦게 익은 토마토. 최소 이정도는 지나야 토마토가 다 익는다.
6. answer를 출력한다.

108ms
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
using namespace std;
int n, m;
int map[1001][1001];
int answer=0;
int dx[] = { 1,-1,0,0 }; // 하 상 우 좌
int dy[] = { 0,0,1,-1 };
struct INFO {
	int r, c;
	int cnt;
};
queue<INFO> q;
void bfs() {
	// 모두 익어있는 경우
	if (q.size() == n * m) {
		answer = 0;
		return;
	}
	
	while (!q.empty()) {
		INFO cur = q.front();
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dx[i];
			int nc = cur.c + dy[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (map[nr][nc] == 0) {
				INFO node;
				node.r = nr;
				node.c = nc;
				node.cnt = cur.cnt + 1;

				q.push(node);
				map[nr][nc] = cur.cnt + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				answer = -1;
				break;
			}
			else if(map[i][j] > answer){
				answer = map[i][j];
			}
		}
		if (answer == -1) break;
	}

	if (answer > 0) answer = answer - 1;
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				INFO node;
				node.r = i;
				node.c = j;
				node.cnt = 1;
				q.push(node);
			}
		}
	}


	bfs();
	
	printf("%d", answer);
	return 0;
}
