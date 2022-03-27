/* 
https://www.acmicpc.net/problem/1780 
종이의 개수 
분할정복 문제
 1. solve(x,y,n) : (x,y)에서 가로로 n개, 세로로 n개의 종이 개수를 확인
 2. check(x,y,n) : (x,y) 좌표값과 (x,y)와 n만큼 떨어진 모든 좌표값이 동일한지 확인. 동일하면 a++, 틀리면 9분할
*/
#include <iostream>
using namespace std;

int n;
int map[3000][3000];
int a[3];
bool check(int x, int y, int n) {
	int cur = map[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (map[i][j] != cur) return false;
		}
	}
	a[cur + 1]++;
	return true;
}
void solve(int x, int y, int n) {
	if (check(x, y, n)) return;
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(x + i* n / 3, y + j*n / 3, n / 3);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	solve(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
