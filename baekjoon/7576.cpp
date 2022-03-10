#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
// 2022.03.10 
// 7시 40분 ~ 8시 35분
int N, M;
int map[1001][1001];
int visited[1001][1001];
int ans;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1,-1 };

struct dd {
	int _x, _y, _num;
	dd(int x, int y, int num) { _x = x; _y = y; _num = num; }
};

queue<dd> q;
void bfs() {
	while (!q.empty()) {
		int cx = q.front()._x;
		int cy = q.front()._y;
		int cnum = q.front()._num;
		q.pop();
		map[cx][cy] = cnum;
		bool push = false;
		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (!visited[nx][ny] && map[nx][ny] == 0) {
				visited[nx][ny] = 1;
				dd nd = dd(nx, ny, cnum + 1);
				q.push(nd);
			}
		}
	}
}

int check() {
	//printf("\n\n");
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//printf("%d ", map[i][j]);
			if (map[i][j] == 0) {
				return -1;
			}
			else if (map[i][j] > max) {
				max = map[i][j];
			}
		}
		//printf("\n");
	}
	return max - 1;
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && map[i][j] == 1) {
				visited[i][j] = 1;
				dd d = dd(i, j, 1);
				q.push(d);
			}
		}
	}
	bfs();
	cout << check();
	return 0;
}
