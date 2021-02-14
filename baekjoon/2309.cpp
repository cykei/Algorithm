//-----------------------------------------------------------------------
// file name : 2309_일곱난쟁이.cpp
// create time : 2021/02/14, 15:37 ~ 16:25
// made by : cykei
// 재귀, 완전탐색
//-----------------------------------------------------------------------

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define scanf scanf_s
using namespace std;
int dwarf[9];
int diff;
int sum;
int visited[9];
void go(int idx, int cnt) {
	if (cnt == 2) {
		if (sum == diff) {
			for (int i = 0; i < 9; i++) {
				if (visited[i]) dwarf[i] = 0;
			}
		}
		return;
	}
	
	for (int i = idx; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			sum += dwarf[i];
			go(i, cnt + 1);
			sum -= dwarf[i];
			visited[i] = 0;
		}
	}
}
int main() {
	int total = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarf[i]);
		total += dwarf[i];
	}
	diff = total - 100;

	go(0, 0);
	sort(dwarf, dwarf + 9);

	for (int i = 2; i < 9; i++) {
		printf("%d\n", dwarf[i]);
	}
	return 0;
}
