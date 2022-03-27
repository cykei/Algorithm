/*
종이의개수 문제와 유사한 문제
분할 정복으로 풀 수 있다.
계속 4분할 하면서 확인.
출력시작할때 "(" ")" 로 감싼다고 한것만 종이의개수 문제와 다른듯.
*/

#include<iostream>
int n;
int map[65][65];
bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (map[x][y] != map[i][j]) return false;
		}
	}
	return true;
}
void solve(int x, int y, int n ) {
	if (check(x, y,n)) {
		printf("%d", map[x][y]);
	}
	else {
		printf("(");
		int dist = n / 2;
		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + i*dist, y + j*dist, dist);
			}
		}
		printf(")");
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	solve(0, 0, n);
	// (x,y)에서 가로 세로 dist만큼의 공간을 탐색, 사분면 번호는 idx
	// idx = 0 : 1사분면
	return 0;
}
